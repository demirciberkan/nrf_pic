/*************************DEFINE OPTIONS AND REQUIREMENTS**********************************/ 
RF24_CS 
RF24_CE 
RF24_IRQ 
SPI_MISO        
SPI_MOSI        
SPI_CLK        
RF24_USE_DMA        //nRF24 can use  SPI DMA for multiple byte transfers(RF24_comm_in and RF24_comm_out functions) 
/*************************SPI handshake and I/O commands***********************************/ 
//Defined macros 
RF24_xfer(xdata)     //Send/receive data through SPI(controls RF24_CS manualy)___DON´T USE RF24_xfer() ALIAS FOR MORE THAN 1 xdata PARAMETER 
RF24_select()        //Controls bit Chipselect 
RF24_unselect()      //Controls bit Chipselect 
RF24_enable()        //Controls bit Chipenable 
RF24_disable()       //Controls bit Chipenable 
RF24_IRQ_state()     //IsOn when receive or transmit Data IRQ asserted 
//Functions 
int   RF24_comm_in(int comm);                            //Send command and receive input(receive only one byte) 
void  RF24_comm_in(int comm, char *datain, int dataSZ);  //Send command and receive input(dataSZ=number of input bytes)(datain=pointer to data for receiving) 
int   RF24_comm_out(int comm, char *dataout, int dataSZ);//Send command and send output string(dataSZ=number of bytes to output)(dataout=pointer to data for sending) 
int   RF24_comm(int comm); 
int   RF24_comm(int comm, int comm1); 
int   RF24_comm(int comm, int32 comm1, int commDS);      //commDS=datasize(1 to 32 bits) 
// 
// 
/*************************General Driver commands******************************************/ 
//Defined macros 
RF24_FLUSH_TX();                          //Flush TX FIFO, used in TX mode 
RF24_FLUSH_RX();                          //Flush RX FIFO, used in RX mode. Should not be executed during transmission of acknowledge, that is, acknowledge package will not be completed. 
RF24_REUSE_TX_PL();                       //(do not check for errors like TX_EMPTY)Reuse last transmitted payload. TX payload reuse is active until W_TX_PAYLOAD or FLUSH TX is executed. TX payload reuse must not be activated or deactivated during package transmission. 
RF24_R_RX_PL_WID();                       //Read RX payload width for the top R_RX_PAYLOAD in the RX FIFO. Note: Flush RX FIFO if the read value is larger than 32 bytes. 
RF24_W_TX_PAYLOAD_NOACK();                //Disables AUTOACK on this specific packet 

RF24_lost_packets();                      //Know how many packets was lost during Transmition(with autoack feature enabled) 
RF24_retry_packets();                     //Know how many retrys for transmit data(TX)(with autoack feature enabled) 
RF24_RX_power_detector();                 //Returns 1 if power is over -65dbm 
RF24_setup_autoretry(delay,retrys);       //delay=0to15(250 to 4000us)(delay between retrys, see datasheet), retrys=0to15(How many TX retrys) 

RF24_FIFO_STATUS();                       //Returns FIFO_STATUS Register 
RF24_FIFO_STATUS_TX_REUSE(fstat);         //(R)make RF24_enable for at least 10µs to Reuse last transmitted payload. TX payload reuse is active until W_TX_PAYLOAD or FLUSH TX is executed. TX_REUSE is set by the SPI command REUSE_TX_PL, and is reset by the SPI commands W_TX_PAYLOAD or FLUSH TX 
RF24_FIFO_STATUS_TX_FULL(fstat);          //(R)TX FIFO buffer full flag 
RF24_FIFO_STATUS_TX_EMPTY(fstat);         //(R)TX FIFO buffer empty 
RF24_FIFO_STATUS_RX_FULL(fstat);          //(R)RX FIFO buffer full flag 
RF24_FIFO_STATUS_RX_EMPTY(fstat);         //(R)RX FIFO buffer empty 

RF24_get_status();                        //Get nRF24 STATUS register in a fast way: It sends NO OPERATION command byte while receives STATUS register byte. 
RF24_STATUS_extract_pipe_number(xstat);   //Return received pipe number(0 to 5) 
RF24_STATUS_RX_buffer_empty(xstat);       //return true if RX_buffer_empty 
RF24_STATUS_TX_buffer_full(xstat);        //return true if TX_buffer_full 
RF24_STATUS_RX_dataready_IRQ(xstat);      //return true if buffer_empty 
RF24_STATUS_TX_datasent_IRQ(xstat);       //return true if buffer_empty 
RF24_STATUS_MAX_retrys_reached_IRQ(xstat);//return true if buffer_empty 
RF24_STATUS_clr_IRQs(xstat);              //clear selected IRQs(in xstat) 
//Functions 
void  RF24_initPorts(); 
void  RF24_default_config();              //Ititializes default configuration for chip nRF24L01+ 
void  RF24_waveout_testing(int channel);  //TX is always on transmitting sinc signal 
int   RF24_TX_SET();                      //Enhanced ShockBurst transmitting payload(return 1 if ok, return other number if error) 
int   RF24_RX_SET();                      //Enhanced ShockBurst receiving payload(return 1 if ok, return other number if error) 
short int RF24_TX_setaddress(char *address, int addrsize, short int ShockBurst);   //Change address for transmiting data(with or without shockburst) 
int   RF24_TX_putbuffer(short int burst, int datasize, char *buffer);   //Transmit data(1 to 32 bytes) to actual address 
int   RF24_TX_reusebuffer();              //Retransmit last TX data present in TX buffer 
int   RF24_RX_getbuffer(int *pipe, int *datasize, char *buffer);        //Receive data(1 to 32 bytes) into buffer 
int   RF24_check_rfsignal();              //Beep if there is RFsignal stronger that -64dB on choosen channel 
void  RF24_check_config();                //Check actual configuration(only for debugging purposes, stop in each delay) 
//Example of using nRF24L01+ functions 
void  RF24_driver_use_example_RXdata();   //Example of using this driver 
void  RF24_driver_use_example_TXdata();   //Example of using this driver 
void  RF24_driver_use_example_TXdata_simple();    //Example of using this driver 
