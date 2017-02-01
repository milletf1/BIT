using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace DiscreteEventSimulator
{
    /****************************************************************************
     * GraphicDisplay is responsible for displaying a graphical representation of 
     * a calendars event list.
     ***************************************************************************/
    class GraphicDisplay 
    {
        //The x position used to draw every area in the graphics display
        private const int MASTER_DRAW_X = 32;

        //Block size is used to dictate the width/height of entities, 
        //and the space needed to hold an entity by the arrival area, ivr, queues, and service desks.
        private const int BLOCK_SIZE = 64;
        
        //Height of title text
        private const float TITLE_HEIGHT = 12;
        
        //Height of the entities' ID text.
        private const float ENTITY_TEXT_HEIGHT = 12;

        //Font used for graphics.
        private const string GRAPHICS_FONT = "MS Reference Sans Serif";

        //Offsets used to determine where to draw an entities ID number.
        private const int ENTITY_ID_OFFSET_X = 22;
        private const int ENTITY_ID_OFFSET_Y = 24;

        //Border width for queues
        private const int BORDER_WIDTH = 1;

        //y postion to start drawing the arrival area.
        private const int ARRIVAL_AREA_Y = 32;
        //y postion to start drawing the arrival area'a title.
        private const int ARRIVAL_TITLE_Y = 14;
        //title string for the arrival area.
        private const string ARRIVAL_TITLE = "Scheduled to Arrive";

        //y postion to start drawing the ivr area.
        private const int IVR_AREA_Y = 128;
        //y postion to start drawing the ivr area's title.
        private const int IVR_TITLE_Y = 110;
        //title string for the ivr area.
        private const string IVR_TITLE = "In Process IVR  Unit";

        //y postion to start drawing the car-stereo queue.
        private const int CAR_STEREO_QUEUE_AREA_Y = 224;
        //y postion to start drawing the car stereo queue's title.
        private const int CAR_STEREO_QUEUE_TITLE_Y = 206;
        //title string for the car stereo queue.
        private const string CAR_STEREO_QUEUE_TITLE = "Waiting in Car-Stereo Queue";

        //y postion to start drawing the car-stereo service desk.
        private const int CAR_STEREO_DESK_AREA_Y = 320;
        //y position to start drawing the car stere service desk's title.
        private const int CAR_STEREO_DESK_TITLE_Y = 302;
        //title string for the car stereo service desk.
        private const string CAR_STEREO_DESK_TITLE = "In Process Car-Stereo Sales Representative";

        //y postion to start drawing the other queue.
        private const int OTHER_QUEUE_AREA_Y = 416;
        //y position to start drawing the other queue's title.
        private const int OTHER_QUEUE_TITLE_Y = 398;
        //title string for other queue.
        private const string OTHER_QUEUE_TITLE = "Waiting in Other Products Queue";

        //y postion to start drawing the other service desk.
        private const int OTHER_DESK_AREA_Y = 512;
        //y position to start drawing the other service desk's title.
        private const int OTHER_DESK_TITLE_Y = 494;
        //title string for other service desk.
        private const string OTHER_DESK_TITLE = "In Process Other Products Sales Representatives";

        //End Constants

        //widths of the areas in this simulation (all heights = BLOCK_SIZE)
        private int ivrWidth;
        private int carStereoQueueWidth;
        private int otherQueueWidth;
        private int carStereoDeskWidth;
        private int otherDeskWidth;

        //Display panel.
        private Panel canvas;   
        //The buffer.
        private Graphics buffer;
        //The buffer draw surface.
        private Bitmap bufferDrawSurface;

        private int screenWidth, screenHeight;
 
        private Calendar calendar;

        //Colors used to draw graphics.
        private Color bgColor = Color.White;
        private Color borderColor = Color.Black;
        private Color textColor = Color.Black;
        private Color ivrColor = Color.Green;
        private Color queueColor = Color.Red;
        private Color deskColor = Color.Blue;
        private Color entityColor = Color.Yellow;

        //Delegate used to access a Calendar object that's running on another thread.
        private delegate void DisplayDelegate();

        /*************
         * Constructor
         ************/
        public GraphicDisplay(Panel panel, Calendar calendar, int maxQueueLength, int carStereoReps, int otherReps, 
            int displayWidth, int displayHeight)
        {
            this.calendar = calendar;
            this.calendar.CalendarUpdate += new Calendar.UpdateHandler(RecieveCalendarUpdate);

            screenWidth = displayWidth;
            screenHeight = displayHeight;

            //Initialize the area widths of the drawn areas.
            InitAreaWidth(maxQueueLength, carStereoReps, otherReps);

            //Initialize graphics.
            InitGraphics(panel, displayWidth, displayHeight);
        }//End Constructor.

        /****************************************************************
         * Initializes the canvas, buffer bitmap, and graphics buffer.
         ***************************************************************/
        private void InitGraphics(Panel panel, int displayWidth, int displayHeight)
        {            
            canvas = panel;

            //Initialize the bitmap that this class draws on.
            bufferDrawSurface = new Bitmap(displayWidth, displayHeight);
            
            //Initialize the graphics object to draw with.
            buffer = Graphics.FromImage(bufferDrawSurface);
        }//End InitGraphics.

        /*******************************************************************
         * Initializea the width of the queues, service desks, and ivr unit. 
         ******************************************************************/
        private void InitAreaWidth(int maxQueueLength, int carStereoReps, int otherReps)
        {
            //Initialize the width of the IVR unit.
            ivrWidth = BLOCK_SIZE * maxQueueLength;
            
            //Initialize the width of the car stereo queue.
            carStereoQueueWidth = BLOCK_SIZE * maxQueueLength;

            //Initialize the width of the other product queue.
            otherQueueWidth = BLOCK_SIZE * maxQueueLength;

            //Initialize the service desks
            carStereoDeskWidth = BLOCK_SIZE * carStereoReps;
            otherDeskWidth = BLOCK_SIZE * otherReps;
        }//End InitAreaWidth.

        /******************************************************************************
         * DrawGraphics is responsible for managing the order in which the graphics are
         * drawn to the canvas.
         *****************************************************************************/
        private void DrawGraphics()
        {
            //Clear the canvas.
            ClearGraphics();
            
            //Draw the areas that the designate queues, service desks etc...
            DrawAreas();

            //Draw the entities.
            DrawEntities();

            //Draw the buffer to screen.
            DrawBufferToScreen();
        }//End DrawGraphics.

        /***********************************************************************
         * DrawEntities draws the event entities in their designated event area.
         **********************************************************************/
        private void DrawEntities()
        {
            //set starting draw points for the entities.
            Point curEntityArrive = new Point(MASTER_DRAW_X, ARRIVAL_AREA_Y);
            Point curEntityIvr = new Point(MASTER_DRAW_X, IVR_AREA_Y);
            Point curEntityCarStereoQueue = new Point(MASTER_DRAW_X, CAR_STEREO_QUEUE_AREA_Y);
            Point curEntityOtherQueue = new Point(MASTER_DRAW_X, OTHER_QUEUE_AREA_Y);
            Point curEntityCarStereoDesk = new Point(MASTER_DRAW_X, CAR_STEREO_DESK_AREA_Y);
            Point curEntityOtherDesk = new Point(MASTER_DRAW_X, OTHER_DESK_AREA_Y);

            //Iterate  through each entity in the calendar's event list.
            foreach (SimEvent se in calendar.EventList)
            {
                /***************************
                 * Determine the event type.
                 **************************/

                //Arrive at call center event.
                if (se is ArriveAtCallCenter)
                { 
                    //Draw the entity.
                    DrawEntity(se.EventEntity.EntityID, curEntityArrive);                    

                    //Increment the position of the next entity that is going to perform this event.
                    curEntityArrive = SetNextEntityPosition(curEntityArrive);
                }
                
                //Complete IVR service event.
                else if (se is CompleteIVRService)
                { 
                    //Draw the entity.
                    DrawEntity(se.EventEntity.EntityID, curEntityIvr);

                    //Increment the position of the next entity that is going to perform this event.
                    curEntityIvr = SetNextEntityPosition(curEntityIvr);
                }

                //End queue wait event.
                else if (se is EndQueueWait)
                {
                    //Determine the entities product type.

                    //Car-stereo
                    if (se.EventEntity.ProductType.CompareTo(ProductData.CAR_STEREO_PRODUCT) == 0)
                    {
                        //Draw the entity.
                        DrawEntity(se.EventEntity.EntityID, curEntityCarStereoQueue);

                        //Increment the position of the next entity that is going to perform this event.
                        curEntityCarStereoQueue = SetNextEntityPosition(curEntityCarStereoQueue);
                    }
                    //Other
                    else
                    {
                        //Draw the entity.
                        DrawEntity(se.EventEntity.EntityID, curEntityOtherQueue);

                        //Increment the position of the next entity that is going to perform this event.
                        curEntityOtherQueue = SetNextEntityPosition(curEntityOtherQueue);
                    }
                }

                //Complete service desk event.
                else if (se is CompleteServiceDesk)
                {
                    //Determine the entities product type.

                    //Car-stereo
                    if (se.EventEntity.ProductType.CompareTo(ProductData.CAR_STEREO_PRODUCT) == 0)
                    {
                        //Draw the entity.
                        DrawEntity(se.EventEntity.EntityID, curEntityCarStereoDesk);

                        //Increment the position of the next entity that is going to perform this event.
                        curEntityCarStereoDesk = SetNextEntityPosition(curEntityCarStereoDesk);
                    }
                    //Other
                    else
                    {
                        //Draw the entity.
                        DrawEntity(se.EventEntity.EntityID, curEntityOtherDesk);

                        //Increment the position of the next entity that is going to perform this event.
                        curEntityOtherDesk = SetNextEntityPosition(curEntityOtherDesk);
                    }
                }
            }
        }//End DrawEntities.

        /***************************************************************************
         * DrawEntity draws an entity at with the given entityID at the given point.
         **************************************************************************/
        private void DrawEntity(int entityId, Point drawPoint)
        {
            //Initialize the drawing components.
            Brush fill = new SolidBrush(entityColor);
            Pen border = new Pen(borderColor, BORDER_WIDTH);
            Brush text = new SolidBrush(textColor);

            //Determine where to draw the entities id number.
            int entityIdX  = drawPoint.X + ENTITY_ID_OFFSET_X;
            int entityIdY = drawPoint.Y + ENTITY_ID_OFFSET_Y;
            Point entityTextPoint = new Point(entityIdX, entityIdY);

            //Draw the background.
            buffer.FillEllipse(fill, drawPoint.X, drawPoint.Y, BLOCK_SIZE, BLOCK_SIZE);

            //Draw the border.
            buffer.DrawEllipse(border, drawPoint.X, drawPoint.Y, BLOCK_SIZE, BLOCK_SIZE);

            //Draw the title.
            buffer.DrawString(Convert.ToString(entityId), new Font(GRAPHICS_FONT, ENTITY_TEXT_HEIGHT), text, entityTextPoint);   
        }//End DrawEntity.

        /********************************************
         * Sets the draw position of the next entity.
         *******************************************/
        private Point SetNextEntityPosition(Point p)
        {
            //Set the new position to the right of the given point and return it.
            int nextPositionX = p.X + BLOCK_SIZE;
            p = new Point(nextPositionX, p.Y);
            return p;
        }//End SetNextEntityPosition.

        /******************************************
         * Draws the graphics buffer to the canvas.
         *****************************************/
        private void DrawBufferToScreen()
        {
            Graphics canvasGraphics = canvas.CreateGraphics();
            canvasGraphics.DrawImage(bufferDrawSurface, 0, 0, new Rectangle(0, 0, screenWidth, screenHeight), GraphicsUnit.Pixel);
        }//End DrawBufferToScreen.

        /*****************************************
         * Manages the drawing of the event areas.
         ****************************************/
        private void DrawAreas()
        {
            //Draw the arrival area.
            DrawArrivalArea();

            //Draw the IVR unit.
            DrawIvr();

            //Draw the Car-stereo queue.
            DrawCarStereoQueue();

            //Draw the other queue.
            DrawOtherQueue();

            //Draw the Car-stereo service desk.
            DrawCarStereoDesk();

            //Draw the other service desk.
            DrawOtherDesk();            
        }//End DrawAreas.

        /****************************************************
         * Draws the arrival area (consists only of a title).
         ***************************************************/
        private void DrawArrivalArea()
        {
            //Initialize the drawing components.
            Brush title = new SolidBrush(textColor);
            Point textPoint = new Point(MASTER_DRAW_X, ARRIVAL_TITLE_Y);

            //Draw the title.
            buffer.DrawString(ARRIVAL_TITLE, new Font(GRAPHICS_FONT, TITLE_HEIGHT), title, textPoint);
        }//End DrawArrivalArea.

        /**************************
         * Draws the IVR unit area.
         *************************/
        private void DrawIvr()
        {
            //Initialize the drawing components.
            Brush fill = new SolidBrush(ivrColor);
            Pen border = new Pen(borderColor, BORDER_WIDTH);
            Brush title = new SolidBrush(textColor);
            Point textPoint = new Point(MASTER_DRAW_X, IVR_TITLE_Y);

            //Draw the background.
            buffer.FillRectangle(fill, MASTER_DRAW_X, IVR_AREA_Y, ivrWidth, BLOCK_SIZE);

            //Draw the border.
            buffer.DrawRectangle(border, MASTER_DRAW_X, IVR_AREA_Y, ivrWidth, BLOCK_SIZE);

            //Draw the title.
            buffer.DrawString(IVR_TITLE, new Font(GRAPHICS_FONT, TITLE_HEIGHT), title, textPoint);
        }//End DrawIvr.

        /**********************************
         * Draws the Car-stereo queue area.
         *********************************/
        private void DrawCarStereoQueue()
        {
            //Initialize the drawing components.
            Brush fill = new SolidBrush(queueColor);
            Pen border = new Pen(borderColor, BORDER_WIDTH);
            Brush title = new SolidBrush(textColor);
            Point TextPoint = new Point(MASTER_DRAW_X, CAR_STEREO_QUEUE_TITLE_Y);

            //Draw the background.
            buffer.FillRectangle(fill, MASTER_DRAW_X, CAR_STEREO_QUEUE_AREA_Y, carStereoQueueWidth, BLOCK_SIZE);

            //Draw the border.
            buffer.DrawRectangle(border, MASTER_DRAW_X, CAR_STEREO_QUEUE_AREA_Y, carStereoQueueWidth, BLOCK_SIZE);

            //Draw the title.
            buffer.DrawString(CAR_STEREO_QUEUE_TITLE, new Font(GRAPHICS_FONT, TITLE_HEIGHT), title, TextPoint);
        }//End DrawCarStereoQueue.

        /*****************************
         * Draws the other queue area.
         ****************************/
        private void DrawOtherQueue()
        {
            //Initialize the drawing components.
            Brush fill = new SolidBrush(queueColor);
            Pen border = new Pen(borderColor, BORDER_WIDTH);
            Brush title = new SolidBrush(textColor);
            Point TextPoint = new Point(MASTER_DRAW_X, OTHER_QUEUE_TITLE_Y);

            //Draw the background.
            buffer.FillRectangle(fill, MASTER_DRAW_X, OTHER_QUEUE_AREA_Y, otherQueueWidth, BLOCK_SIZE);

            //Draw the border.
            buffer.DrawRectangle(border, MASTER_DRAW_X, OTHER_QUEUE_AREA_Y, otherQueueWidth, BLOCK_SIZE);
            
            //Draw the title.
            buffer.DrawString(OTHER_QUEUE_TITLE, new Font(GRAPHICS_FONT, TITLE_HEIGHT), title, TextPoint);
        }//End DrawOtherQueue.

        /*************************************************
         * Draws the Car-stereo product service desk area.
         ************************************************/
        private void DrawCarStereoDesk()
        {
            //Initialize the drawing components.
            Brush fill = new SolidBrush(deskColor);
            Pen border = new Pen(borderColor, BORDER_WIDTH);
            Brush title = new SolidBrush(textColor);
            Point TextPoint = new Point(MASTER_DRAW_X, CAR_STEREO_DESK_TITLE_Y);

            //Draw the background.
            buffer.FillRectangle(fill, MASTER_DRAW_X, CAR_STEREO_DESK_AREA_Y, carStereoDeskWidth, BLOCK_SIZE);

            //Draw the border.
            buffer.DrawRectangle(border, MASTER_DRAW_X, CAR_STEREO_DESK_AREA_Y, carStereoDeskWidth, BLOCK_SIZE);

            //Draw the title.
            buffer.DrawString(CAR_STEREO_DESK_TITLE, new Font(GRAPHICS_FONT, TITLE_HEIGHT), title, TextPoint);
        }//End DrawCarStereoDesk.

        /********************************************
         * Draws the other product service desk area.
         *******************************************/
        private void DrawOtherDesk()
        {
            //Initialize the drawing components.
            Brush fill = new SolidBrush(deskColor);
            Pen border = new Pen(borderColor, BORDER_WIDTH);
            Brush title = new SolidBrush(textColor);
            Point TextPoint = new Point(MASTER_DRAW_X, OTHER_DESK_TITLE_Y);

            //Draw the background.
            buffer.FillRectangle(fill, MASTER_DRAW_X, OTHER_DESK_AREA_Y, otherDeskWidth, BLOCK_SIZE);

            //Draw the border.
            buffer.DrawRectangle(border, MASTER_DRAW_X, OTHER_DESK_AREA_Y, otherDeskWidth, BLOCK_SIZE);

            //Draw the title.
            buffer.DrawString(OTHER_DESK_TITLE, new Font(GRAPHICS_FONT, TITLE_HEIGHT), title, TextPoint);
        }//End DrawOtherDesk.

        /*****************************
         * Clears the graphics buffer.
         ****************************/
        private void ClearGraphics()
        {
            Brush b = new SolidBrush(bgColor);
            buffer.FillRectangle(b, 0, 0, screenWidth, screenHeight);
        }//End ClearGraphics.

        /*******************************************************************************************
         * RecieveCalendarUpdate watches for the simulation calendar to fire a CalendarUpdate event.
         ******************************************************************************************/
        public void RecieveCalendarUpdate(object sender, EventArgs e)
        {
            //Check if the canvas needs to be invoked before use
            if (this.canvas.InvokeRequired)
            {
                //If it does, initialize a DisplayDelegate and invoke it.
                DisplayDelegate displayHandler = new DisplayDelegate(DrawGraphics);
                this.canvas.Invoke(displayHandler);
            }
            else
                //Otherwise just call DrawGraphics.
                DrawGraphics();
        }//End RecieveCalendarUpdate.
    }
}
