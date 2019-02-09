#line 1 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
#line 1 "c:/users/dumitru/desktop/dima/alta_2_compressor_display/controller_code/mikroc pro for arm/controller_objects.h"
#line 27 "c:/users/dumitru/desktop/dima/alta_2_compressor_display/controller_code/mikroc pro for arm/controller_objects.h"
typedef enum {_pbsClearSector, _pbsFillSector} TProgressBarSector;

typedef enum {_taLeft, _taCenter, _taRight} TTextAlign;
typedef enum {_tavTop, _tavMiddle, _tavBottom} TTextAlignVertical;

typedef struct Screen TScreen;


extern void selectPage();
extern void checkResponse();
extern unsigned long check_packet_status();
extern void constructPacket();

extern void modbus_configure(unsigned int _time_out, unsigned int _polling,unsigned char _retry_count);
extern int calc_temperature(unsigned int adcsum);
extern float ReadHighPressure (int high_press);
extern float ReadLowPressure (int low_press);
extern void main_page();
extern void sensor_1(unsigned char num_page);
extern void data_eeprom();
extern void HP_display(int pressure);
extern void LP_display(int pressure);
extern void find_errors();
extern void count_steps(unsigned char num_page);
extern void working_time(unsigned char num_page);
extern void void startPage();
extern void schema1_page();
extern void schema2_page();



 typedef struct
{

 unsigned char id;
 unsigned char function;
 unsigned int address;
 unsigned int no_of_registers;
 unsigned int* register_array;


 unsigned int requests;
 unsigned int successful_requests;
 unsigned long total_errors;
 unsigned int retries;
 unsigned int _timeout;
 unsigned int incorrect_id_returned;
 unsigned int incorrect_function_returned;
 unsigned int incorrect_bytes_returned;
 unsigned int checksum_failed;
 unsigned int buffer_errors;


 unsigned int illegal_function;
 unsigned int illegal_data_address;
 unsigned int illegal_data_value;
 unsigned char misc_exceptions;


 unsigned char connection;

}Packet;

enum _system {

ELECT_HEAT,
PROG_REL,
TIME_REL,
TRV_CORRECT_1=391,
TRV_CORRECT_2=392,
NUM_P_HEAT_1,
NUM_P_SOURS_1,
NUM_REV_1,
NUM_COM_1,
NUM_P_HEAT_2,
NUM_P_SOURS_2,
NUM_REV_2,
NUM_COM_2,

K_FLOW_HEAT,
K_FLOW_SOURS,
TOTAL_ERRORS,


VOLT_A=470,
VOLT_B=480,
VOLT_C=490,
CURR_A=500,
CURR_B=510,
CURR_C=520,

TRV_STEPS_1=61, TRV_STEPS_2=62,
BAC_TEMP=71,
DHW_TEMP=81,
SOURC_IN_1=91, SOURC_IN_2=92,
SOURC_OUT_1=101,SOURC_OUT_2=102,
ERRORS_1=111,ERRORS_2=112,

CONDENS_TEMP_1=121,CONDENS_TEMP_2=122,
SUCT_TEMP_1=131, SUCT_TEMP_2=132,
S_COOL_1=141,S_COOL_2=142,
S_HEAT_1=151,S_HEAT_2=152,
HEAT_IN_1=161,HEAT_IN_2=162,
HEAT_OUT_1=171,HEAT_OUT_2=172,
HIGH_PRESS_1=181, HIGH_PRESS_2 =182,
LOW_PRESS_1=191,LOW_PRESS_2=192,
EXAUST_TEMP_1=201,EXAUST_TEMP_2=202,






TIM_COM_1=341,TIM_COM_2=342,
TIM_P_HEAT_1=351, TIM_P_HEAT_2=352,
TIM_P_SOURS_1=371,TIM_P_SOURS_2=372,
TIM_REV_1=381, TIM_REV_2=382,



COM_STATE_1=11, COM_STATE_2=12,
PUMP_SOURS_STATE_1=21, PUMP_SOURS_STATE_2=22,
PUMP_HEAT_STATE_1=31, PUMP_HEAT_STATE_2=32,
REV_STATE_1=41,REV_STATE_2=42,
THREE_STATE=51,
PUSH_DEFROS=393,

COMP_DEL=10,
HEAT_DEL=20,
SOURS_DEL=30,
REVERS_DEL=40,
THREE_WAY_DEL=50,
COOL_MAX=60,
COOL_MIN=70,
HEAT_MAX=80,
HEAT_MIN=90,
DEL_HEAT_MAX=100,
DEL_HEAT_MIN=110,
DEL_SOURS_MAX=120,
DEL_SOURS_MIN=130,
DIFF_COOL=140,
DIFF_DHW=150,
DIFF_HEAT=160,
AIRE_TO_WATER=170,
EXAUST_MAX=180,
COOL=190,
HEAT=200,
HEATWATER=210,
HP_MAX=220,
LP_MAX=230,
HP_MIN=240,
LP_MIN=250,
S_COOL_MAX=260,
S_COOL_MIN=270,
S_HEAT_MAX=280,
S_HEAT_MIN=290,
NUM_THREE =300,
POWER=310,
SET_COOL=320,
SET_DHW=330,
SET_HEAT=340,
TEMP_DEFROST=350,
TIME_DEFROST=360,
TEMP_OUT=370,
TEMP_STOP_DEFROST=380,
TIM_THREE=390,
NOMB_COMPRESSORS=400,
REVERS_MOD=410,
TRV_DEL=420,
SOURS_MAX=430,
SOURS_MIN=440,
DEL_DHW_MAX=450,
DEL_DHW_MIN=460,
POWER_380=470,
TIME_BETWEEN_DEF=480
};


 typedef enum _system regAdress;
 extern regAdress adressReg;
 extern unsigned char nomReg;
 extern unsigned char countPacket;

extern void send_data_packet(enum _system adress,unsigned char no_reg);
extern void reciev_data_packet(enum _system adress,unsigned char no_reg);



typedef struct
{
 unsigned short RTC_Hour_Tens;
 unsigned short RTC_Hour_Units;
 unsigned short RTC_Min_Tens;
 unsigned short RTC_Min_Units;
 unsigned short RTC_Sec_Tens;
 unsigned short RTC_Sec_Units;
 unsigned short RTC_H12;
}RTC_TimeTypeDef;


typedef struct
{
 unsigned short RTC_DayofWeek;
 unsigned short RTC_Date_Tens;
 unsigned short RTC_Date_Units;
 unsigned short RTC_Month_Tens;
 unsigned short RTC_Month_Units;
 unsigned short RTC_Year_Tens;
 unsigned short RTC_Year_Units;
}RTC_DateTypeDef;

extern short RTC_Init (unsigned PREDIV_Sync, unsigned short PREDIV_Async, int HR_Format);
extern short RTC_SetTime (RTC_TimeTypeDef *RTC_TimeStruct, int Calibration_Value);
extern short RTC_SetDate(RTC_DateTypeDef *RTC_DateStruct);
extern void Message (char arg[]);
extern void RTC_GetTime(RTC_TimeTypeDef *RTC_TimeStruct);
extern void RTC_GetDate(RTC_DateTypeDef *RTC_DateStruct);
extern void RTC_PrintTime(RTC_TimeTypeDef *RTC_TimeStruct);
extern void RTC_PrintDate(RTC_DateTypeDef *RTC_DateStruct);


typedef struct {
 unsigned int X_Min;
 unsigned int X_Max;
 unsigned int Y_Min;
 unsigned int Y_Max;
 char Rotate;
} TTPConstants;

typedef struct Button {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Active;
 char Transparent;
 char *Caption;
 TTextAlign TextAlign;
 TTextAlignVertical TextAlignVertical;
 const char *FontName;
 unsigned int Font_Color;
 char VerticalText;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 char PressColEnabled;
 unsigned int Press_Color;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TButton;

typedef struct Button_Round {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Active;
 char Transparent;
 char *Caption;
 TTextAlign TextAlign;
 TTextAlignVertical TextAlignVertical;
 const char *FontName;
 unsigned int Font_Color;
 char VerticalText;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 char Corner_Radius;
 char PressColEnabled;
 unsigned int Press_Color;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TButton_Round;

typedef struct Label {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char *Caption;
 const char *FontName;
 unsigned int Font_Color;
 char VerticalText;
 char Visible;
 char Active;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TLabel;

typedef struct Image {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 const char *Picture_Name;
 char Visible;
 char Active;
 char Picture_Type;
 char Picture_Ratio;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TImage;

typedef const struct CImage {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 const char *Picture_Name;
 char Visible;
 char Active;
 char Picture_Type;
 char Picture_Ratio;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TCImage;

typedef struct Circle {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Radius;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Active;
 char Transparent;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 char PressColEnabled;
 unsigned int Press_Color;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TCircle;

typedef struct CircleButton {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Radius;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Active;
 char Transparent;
 char *Caption;
 TTextAlign TextAlign;
 TTextAlignVertical TextAlignVertical;
 const char *FontName;
 unsigned int Font_Color;
 char VerticalText;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 char PressColEnabled;
 unsigned int Press_Color;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TCircleButton;

typedef struct Box {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Active;
 char Transparent;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 char PressColEnabled;
 unsigned int Press_Color;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TBox;

typedef struct Box_Round {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Active;
 char Transparent;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 char Corner_Radius;
 char PressColEnabled;
 unsigned int Press_Color;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TBox_Round;

typedef struct Line {
 TScreen* OwnerScreen;
 char Order;
 unsigned int First_Point_X;
 unsigned int First_Point_Y;
 unsigned int Second_Point_X;
 unsigned int Second_Point_Y;
 char Pen_Width;
 char Visible;
 unsigned int Color;
} TLine;

typedef struct ProgressBar {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char Pen_Width;
 unsigned int Pen_Color;
 char Visible;
 char Transparent;
 char *Caption;
 const char *FontName;
 unsigned int Font_Color;
 char Gradient;
 char Gradient_Orientation;
 unsigned int Gradient_Start_Color;
 unsigned int Gradient_End_Color;
 unsigned int Color;
 unsigned int Background_Color;
 unsigned int Min;
 unsigned int Max;
 unsigned int Position;
 unsigned int Prev_Position;
 char Show_Position;
 char Show_Percentage;
 char Smooth;
 char Rounded;
 char Corner_Radius;
} TProgressBar;

struct Screen {
 unsigned int Color;
 unsigned int Width;
 unsigned int Height;
 unsigned int ObjectsCount;
 unsigned int ButtonsCount;
 TButton * const code *Buttons;
 unsigned int Buttons_RoundCount;
 TButton_Round * const code *Buttons_Round;
 unsigned int LabelsCount;
 TLabel * const code *Labels;
 unsigned int ImagesCount;
 TImage * const code *Images;
 unsigned int CImagesCount;
 TCImage * const code *CImages;
 unsigned int CirclesCount;
 TCircle * const code *Circles;
 unsigned int CircleButtonsCount;
 TCircleButton * const code *CircleButtons;
 unsigned int BoxesCount;
 TBox * const code *Boxes;
 unsigned int Boxes_RoundCount;
 TBox_Round * const code *Boxes_Round;
 unsigned int LinesCount;
 TLine * const code *Lines;
 unsigned int ProgressBarsCount;
 TProgressBar * const code *ProgressBars;
};

extern TScreen HOME;
extern TBox_Round BoxRound8;
extern TBox Set_Heat_Box;
extern TBox Set_Dhw_Box;
extern TImage background;
extern TBox_Round Heat_Windows;
extern TBox HEAT_button_redraw;
extern TBox DHW_button_redraw;
extern TBox_Round DWN_Windows;
extern TBox_Round Brine_Windows;
extern TImage Image20;
extern TBox_Round Wheater_Windows;
extern TImage Image44;
extern TImage Image61;
extern TImage Main_ON;
extern TImage Main_OFF;
extern TButton_Round DHW_Seting;
extern TLabel Label53;
extern TLabel Label38;
extern TLabel Label39;
extern TLabel Label4;
extern TLabel Label20;
extern TLine Brine_Line;
extern TButton_Round Heat_Setting;
extern TCircle alarm_led;
extern TCircle radio_led;
extern TButton_Round bar_heating;
extern TButton_Round bar_DHW;
extern TCircle dhw_led;
extern TCircle heat_led;
extern TLine Line16;
extern TLabel Label140;
extern TLabel Label141;
extern TButton_Round bar_weather;
extern TImage Weather_Icon;
extern TButton_Round bar_brine;
extern TImage Brine_Icon;
extern TImage MainBut3;
extern TImage MainBut4;
extern TImage clock_icon;
extern TImage microSD_icon;
extern TImage radio_icon;
extern TImage dhw_icon;
extern TLabel Label25;
extern TImage cool_icon;
extern TImage Image28;
extern TLabel dhw_celc;
extern TLabel dhw_point;
extern TLabel heat_point;
extern TLabel heat_celc;
extern TLabel TEMP_Setting_value;
extern TLabel DHW_Setting_value;
extern TImage WiFi_on_icon;
extern TImage Image163;
extern TImage Image167;
extern TImage Image168;
extern TImage Image169;
extern TImage Image26;
extern TImage Image170;

extern TButton_Round dhw_T;
extern TButton_Round heat_T;

extern TButton_Round DHW_UP;
extern TButton_Round DHW_DOWN;
extern TButton_Round HEAT_Down;
extern TButton_Round HEAT_UP;
extern TButton_Round ON_OFF_Heat_Cool;
extern TButton_Round ON_OFF_DHW;
extern TImage Image25;
extern TImage Image40;
extern TImage Image87;
extern TImage heat_icon;
extern TImage MainBut1;
extern TImage MainBut2;
extern TImage MainBut5;
extern TBox_Round BoxRound5;
extern TLabel weather_temp_main;
extern TBox_Round BoxRound6;
extern TLabel humedity_main;
extern TBox_Round BoxRound7;
extern TLabel prassure_main;
extern TButton_Round dhw_T;
extern TButton_Round heat_T;
extern TButton_Round sourc_out_TEMP;
extern TButton_Round sign_OUT;
extern TButton_Round sourc_in_T;
extern TButton_Round sign_IN;
extern TButton_Round dhw_dec;
extern TButton_Round heat_dec;
extern TButton_Round sourc_in_dec;
extern TButton_Round source_out_dec;
extern TBox_Round Messages_Box;
extern TLabel DateTime;
extern TButton_Round * const code Screen1_Buttons_Round[22];
extern TLabel * const code Screen1_Labels[18];
extern TImage * const code Screen1_Images[30];
extern TCircle * const code Screen1_Circles[4];
extern TBox * const code Screen1_Boxes[4];
extern TBox_Round * const code Screen1_Boxes_Round[9];
extern TLine * const code Screen1_Lines[2];

extern TScreen USER_MENU;
extern TImage Image30;
extern TImage Image105;
extern TImage Image60;
extern TImage Image51;
extern TImage Image50;
extern TImage Image49;
extern TImage Image48;
extern TImage Image39;
extern TImage Image52;
extern TImage Image56;
extern TImage Image54;
extern TImage Image55;
extern TLabel User_menu_label;
extern TLabel User_time_label;
extern TLabel User_c_label;
extern TLabel User_lan_label;
extern TLabel User_errors_label;
extern TLabel User_timers_label;
extern TLabel User_events_label;
extern TLabel User_energy_label;
extern TLabel User_furnance_label;
extern TLabel User_defrost_label;
extern TLabel Label77;
extern TImage user_set_time;
extern TImage user_check_temperature;
extern TImage user_set_LAN;
extern TImage user_check_errors;
extern TImage user_set_timers;
extern TImage User_history_check;
extern TImage user_check_energy;
extern TImage admin_set_system;
extern TImage user_check_graph;
extern TImage Image57;
extern TImage user_defrost;
extern TButton_Round Home_b1;
extern TImage user_hysterezis;
extern TImage user_setting;
extern TLabel User_operational_label;
extern TLabel User_hysterezis_label;
extern TLabel User_system_label;
extern TButton_Round * const code Screen2_Buttons_Round[1];
extern TLabel * const code Screen2_Labels[14];
extern TImage * const code Screen2_Images[25];

extern TScreen EEV;
extern TImage Image27;
extern TImage Image173;
extern TButton_Round DEC_EEV1;
extern TButton_Round INC_EEV1;
extern TProgressBar Red_bar;
extern TLabel EEV1_set_step_label;
extern TLabel EEV1_label;
extern TButton_Round Home_b2;
extern TButton_Round Back_b2;
extern TButton_Round Next_b1;
extern TButton_Round EEV1_superheat;
extern TButton_Round EEV1_value;
extern TCircleButton CircleButton9;
extern TButton_Round ButtonRound1;
extern TButton_Round * const code Screen3_Buttons_Round[8];
extern TLabel * const code Screen3_Labels[2];
extern TImage * const code Screen3_Images[2];
extern TCircleButton * const code Screen3_CircleButtons[1];
extern TProgressBar * const code Screen3_ProgressBars[1];

extern TScreen Keyboard;
extern TImage Image31;
extern TButton_Round _1;
extern TButton_Round _2;
extern TButton_Round _3;
extern TButton_Round _4;
extern TButton_Round _5;
extern TButton_Round _6;
extern TButton_Round _7;
extern TButton_Round _8;
extern TButton_Round _9;
extern TButton_Round _0;
extern TButton_Round _Q;
extern TButton_Round _W;
extern TButton_Round _E;
extern TButton_Round _R;
extern TButton_Round _T;
extern TButton_Round _Y;
extern TButton_Round _U;
extern TButton_Round _I;
extern TButton_Round _O;
extern TButton_Round _P;
extern TButton_Round _A;
extern TButton_Round _S;
extern TButton_Round _D;
extern TButton_Round _F;
extern TButton_Round _G;
extern TButton_Round _H;
extern TButton_Round _J;
extern TButton_Round _K;
extern TButton_Round _L;
extern TButton_Round _Z;
extern TButton_Round _X;
extern TButton_Round _C;
extern TButton_Round _V;
extern TButton_Round _B;
extern TButton_Round _N;
extern TButton_Round _M;
extern TButton_Round Clear;
extern TButton_Round CAPS_Switch;
extern TButton_Round SPACE;
extern TBox Password_box;
extern TLabel Label23;
extern TBox Admin_box;
extern TLabel Label24;
extern TLabel Keyboard_label;
extern TButton_Round _DEL;
extern TButton_Round _Colon;
extern TButton_Round _Comma;
extern TButton_Round _Slash;
extern TButton_Round ENTER;
extern TButton_Round Home_b3;
extern TButton_Round * const code Screen4_Buttons_Round[45];
extern TLabel * const code Screen4_Labels[3];
extern TImage * const code Screen4_Images[1];
extern TBox * const code Screen4_Boxes[2];

extern TScreen SetRTC;
extern TImage Image32;
extern TButton Ten_minutesUp;
extern TButton Ten_minutesDwn;
extern TButton Unit_minutesUp;
extern TButton Unit_minutesDwn;
extern TButton SetDateAndTime;
extern TLabel Year_word;
extern TLabel Month_Word;
extern TLabel Day_word;
extern TLabel Hour_word;
extern TLabel Min_word;
extern TButton Day_unitUp;
extern TButton Day_unitDwn;
extern TButton Unit_hoursUp;
extern TButton Unit_hoursDwn;
extern TButton OneDayUp;
extern TButton OneDayDwn;
extern TLine LineSlash;
extern TButton TenDayUp;
extern TButton TenDayDwn;
extern TButton MonthDateUp;
extern TButton MonthDateDwn;
extern TButton TenYearUp;
extern TButton TenYearDwn;
extern TButton OneYearUp;
extern TButton OneYearDwn;
extern TLabel Time_setting_label;
extern TButton_Round home_b4;
extern TButton_Round Back_b3;
extern TButton Button1;
extern TButton Button3;
extern TButton Button4;
extern TButton Button8;
extern TButton Button12;
extern TButton Button21;
extern TButton Button24;
extern TButton Button40;
extern TButton Button43;
extern TButton * const code Screen5_Buttons[28];
extern TButton_Round * const code Screen5_Buttons_Round[2];
extern TLabel * const code Screen5_Labels[6];
extern TImage * const code Screen5_Images[1];
extern TLine * const code Screen5_Lines[1];

extern TScreen ERRORS;
extern TImage Image45;
extern TLabel Error_label;
extern TLabel Error_message;
extern TLabel Text_error;
extern TLabel Label2;
extern TButton_Round Home_b5;
extern TButton_Round Back_b4;
extern TButton_Round * const code Screen6_Buttons_Round[2];
extern TLabel * const code Screen6_Labels[4];
extern TImage * const code Screen6_Images[1];

extern TScreen PASSWORD;
extern TImage Image23;
extern TLabel Password_label;
extern TButton_Round Admin_Set;
extern TLabel Admin_text;
extern TButton_Round Home_b6;
extern TButton_Round Back_b5;
extern TButton_Round * const code Screen7_Buttons_Round[3];
extern TLabel * const code Screen7_Labels[2];
extern TImage * const code Screen7_Images[1];

extern TScreen GAUGE1;
extern TImage Image38;
extern TImage LP1_gauge;
extern TImage HP1_gauge;
extern TLine HP_arrow;
extern TLabel Gauge_label;
extern TLine LP_arrow;
extern TImage Image104;
extern TButton_Round Home_b7;
extern TButton_Round Next_b2;
extern TCircleButton CircleButton8;
extern TButton_Round * const code Screen8_Buttons_Round[2];
extern TLabel * const code Screen8_Labels[1];
extern TImage * const code Screen8_Images[4];
extern TCircleButton * const code Screen8_CircleButtons[1];
extern TLine * const code Screen8_Lines[2];

extern TScreen SYSTEM_SET;
extern TImage Image81;
extern TImage Image300;
extern TLabel System_setting_label;
extern TLabel sys_access;
extern TLabel Label138;
extern TLabel Label139;
extern TLabel Label142;
extern TLabel Label143;
extern TLabel Label144;
extern TLabel Label145;
extern TImage Image90;
extern TImage Image91;
extern TImage system_delay;
extern TImage system_limits;
extern TLabel Label238;
extern TButton System_Set_Message;
extern TImage Image85;
extern TImage Image92;
extern TImage Image88;
extern TImage Image93;
extern TImage system_history;
extern TImage Image89;
extern TImage Image83;
extern TImage system_EEV;
extern TImage system_pass;
extern TImage system_mode;
extern TImage system_graph;
extern TImage system_microSD;
extern TButton_Round Home_b8;
extern TButton_Round Back_b30;
extern TButton * const code Screen9_Buttons[1];
extern TButton_Round * const code Screen9_Buttons_Round[2];
extern TLabel * const code Screen9_Labels[9];
extern TImage * const code Screen9_Images[18];

extern TScreen DELAY_MENU;
extern TImage delay_bgd;
extern TImage Image306;
extern TImage Image307;
extern TImage Image308;
extern TImage Image309;
extern TImage Image314;
extern TImage Image313;
extern TImage Image312;
extern TImage Image344;
extern TImage Image345;
extern TImage Image346;
extern TImage Image315;
extern TImage Image347;
extern TImage Image348;
extern TImage Image311;
extern TImage Image310;
extern TImage Image316;
extern TImage Image317;
extern TImage Image349;
extern TBox Box63;
extern TBox Box64;
extern TBox Box66;
extern TImage Delay_Source_UP;
extern TImage Delay_heat_pump_up;
extern TImage Delay_reversing_UP;
extern TImage Delay_trv_up;
extern TImage Delay_DHW_valve_UP;
extern TImage Delay_compressor_UP;
extern TImage Delay_Source_SET;
extern TImage Delay_heat_pump_SET;
extern TImage Delay_reversing_SET;
extern TImage Delay_EEV_SET;
extern TImage Delay_DHW_valve_SET;
extern TImage Delay_compressor_SET;
extern TLabel Delay_setting_label;
extern TButton_Round Home_b9;
extern TButton_Round Back_b6;
extern TImage Delay_Source_DOWN;
extern TImage Delay_heat_pump_DOWN;
extern TImage Delay_reversing_DOWN;
extern TImage Delay_trv_DOWN;
extern TImage Delay_DHW_valve_DOWN;
extern TImage Delay_compressor_DOWN;
extern TButton_Round Delay_Source;
extern TButton_Round Delay_heat_pump;
extern TButton_Round Delay_reversing;
extern TButton_Round Delay_EEV;
extern TButton_Round Delay_DHW_valve;
extern TButton_Round Delay_compressor;
extern TButton_Round * const code Screen10_Buttons_Round[8];
extern TLabel * const code Screen10_Labels[1];
extern TImage * const code Screen10_Images[37];
extern TBox * const code Screen10_Boxes[3];

extern TScreen SYSTEM_EVENTS;
extern TImage Image171;
extern TButton_Round Home_b10;
extern TButton_Round Back_b7;
extern TButton_Round Next_b3;
extern TButton_Round Time_source1;
extern TButton_Round Time_heat1;
extern TButton_Round Time_Electric;
extern TButton_Round Time_reversing1;
extern TButton_Round Time_compressor1;
extern TButton_Round Time_furnance;
extern TLabel total_time_label;
extern TCircleButton CircleButton6;
extern TLabel Label6;
extern TButton_Round * const code Screen11_Buttons_Round[9];
extern TLabel * const code Screen11_Labels[2];
extern TImage * const code Screen11_Images[1];
extern TCircleButton * const code Screen11_CircleButtons[1];

extern TScreen LIMITS1;
extern TImage Image102;
extern TImage Image200;
extern TImage Image205;
extern TImage Image206;
extern TImage Image207;
extern TImage Image208;
extern TImage Image209;
extern TImage Image218;
extern TImage Image219;
extern TImage Image220;
extern TImage Image221;
extern TImage Image222;
extern TImage Image223;
extern TImage Image246;
extern TImage Image247;
extern TImage Image248;
extern TImage Image249;
extern TImage Image250;
extern TImage Image251;
extern TImage Down_1_;
extern TImage Down_2_;
extern TImage Down_3_;
extern TImage Down_4_;
extern TImage Down_5_;
extern TImage Down_6_;
extern TImage Up_1_;
extern TImage Up_2_;
extern TImage Up_3_;
extern TImage Up_4_;
extern TImage Up_5_;
extern TImage Up_6_;
extern TImage Set_1_;
extern TImage Set_2_;
extern TImage Set_3_;
extern TImage Set_4_;
extern TImage Set_5_;
extern TImage Set_6_;
extern TButton_Round Set_min_heating_HP;
extern TButton_Round Set_max_heating_HP;
extern TButton_Round Set_max_exhaust;
extern TButton_Round Set_min_source_temp;
extern TButton_Round Set_max_source_temp;
extern TButton_Round Set_min_delta_heat;
extern TButton_Round Home_b11;
extern TButton_Round Back_b8;
extern TButton_Round Next_b4;
extern TLabel Settings1_label;
extern TCircleButton CircleButton1;
extern TButton_Round * const code Screen12_Buttons_Round[9];
extern TLabel * const code Screen12_Labels[1];
extern TImage * const code Screen12_Images[37];
extern TCircleButton * const code Screen12_CircleButtons[1];

extern TScreen LIMITS2;
extern TImage Image3;
extern TImage Image186;
extern TImage Image257;
extern TImage Image256;
extern TImage Image255;
extern TImage Image254;
extern TImage Image253;
extern TImage Image252;
extern TImage Image224;
extern TImage Image225;
extern TImage Image226;
extern TImage Image227;
extern TImage Image228;
extern TImage Image229;
extern TImage Image215;
extern TImage Image214;
extern TImage Image213;
extern TImage Image212;
extern TImage Image211;
extern TImage Image210;
extern TImage Down_8_;
extern TImage Down_10_;
extern TImage Down_11_;
extern TImage Down_9_;
extern TImage Down_12_;
extern TImage Up_8_;
extern TImage Up_10_;
extern TImage Up_11_;
extern TImage Up_9_;
extern TImage Up_12_;
extern TImage Set_8_;
extern TImage Set_10_;
extern TImage Set_11_;
extern TImage Set_9_;
extern TImage Set_12_;
extern TButton_Round Set_max_delta_heat;
extern TButton_Round Set_min_delta_DHW;
extern TButton_Round Set_min_delta_source;
extern TButton_Round Set_max_source_delta;
extern TButton_Round Set_max_delta_DHW;
extern TButton_Round Set_preset_time_electric;
extern TImage Down_7_;
extern TImage Up_7_;
extern TImage Set_7_;
extern TButton_Round Home_b12;
extern TButton_Round Back_b9;
extern TButton_Round Next_b5;
extern TLabel Settings2_label;
extern TCircleButton CircleButton2;
extern TButton_Round * const code Screen13_Buttons_Round[9];
extern TLabel * const code Screen13_Labels[1];
extern TImage * const code Screen13_Images[38];
extern TCircleButton * const code Screen13_CircleButtons[1];

extern TScreen SENSOR1;
extern TImage Image380;
extern TLabel Sensors2_label;
extern TLabel Label285;
extern TLabel Label286;
extern TLabel Label287;
extern TLabel Label288;
extern TLabel Label289;
extern TLabel Label290;
extern TLabel Label293;
extern TLabel Label294;
extern TButton_Round S_Brine_Inlet_1;
extern TButton_Round S_Brine_Outlet_1;
extern TButton_Round S_Heat_Inlet_1;
extern TButton_Round S_Heat_Outlet_1;
extern TButton_Round S_Compressor_1;
extern TButton_Round S_DHW;
extern TButton_Round S_Superheat_1;
extern TButton_Round S_Subcool_1;
extern TLabel Label297;
extern TLabel Label298;
extern TLabel Label299;
extern TLabel Label300;
extern TLabel Label301;
extern TLabel Label302;
extern TLabel Label303;
extern TLabel Label304;
extern TLabel Label305;
extern TLabel Label306;
extern TLabel Label309;
extern TLabel Label310;
extern TLabel Label315;
extern TLabel Label316;
extern TLabel Label317;
extern TLabel Label318;
extern TLabel Label319;
extern TButton_Round S_Source_Flow_1;
extern TLabel Label320;
extern TButton_Round S_Heat_Flow_1;
extern TLabel Label321;
extern TLabel Label322;
extern TButton_Round SS_tank;
extern TLabel Label12;
extern TLabel Label13;
extern TLabel Label14;
extern TButton_Round S_condenser_1;
extern TButton_Round S_suction_1;
extern TLabel Label15;
extern TLabel Label17;
extern TLabel Label18;
extern TLabel Label28;
extern TLabel Label31;
extern TLabel Label32;
extern TButton_Round Home_b13;
extern TButton_Round Back_b10;
extern TCircleButton CircleButton10;
extern TButton_Round S_Low_Pressure_1;
extern TButton_Round S_High_Pressure_1;
extern TLabel Label70;
extern TLabel Label72;
extern TButton_Round Next_b6;
extern TLabel Label27;
extern TLabel Label35;
extern TButton_Round BrineIN_sign;
extern TButton_Round BrineOUT_sign;
extern TButton_Round Super_sign;
extern TButton_Round Cond_sign;
extern TButton_Round Cool_sign;
extern TButton_Round * const code Screen14_Buttons_Round[23];
extern TLabel * const code Screen14_Labels[42];
extern TImage * const code Screen14_Images[1];
extern TCircleButton * const code Screen14_CircleButtons[1];

extern TScreen LIMITS4;
extern TImage Image192;
extern TImage Image33;
extern TImage Image34;
extern TImage Image266;
extern TImage Image265;
extern TImage Image264;
extern TImage Image243;
extern TImage Image244;
extern TImage Image245;
extern TImage Image24;
extern TButton_Round Home_b14;
extern TButton_Round Next_b7;
extern TImage Image236;
extern TImage Image237;
extern TImage Image238;
extern TImage Image53;
extern TImage Image86;
extern TImage Image95;
extern TButton_Round Set_max_superheat;
extern TButton_Round Set_min_subcooling;
extern TButton_Round Set_max_subcooling;
extern TButton_Round Set_max_high_pressure;
extern TButton_Round Set_min_lhigh_pressure;
extern TLabel Seeting4_label;
extern TCircleButton CircleButton4;
extern TButton_Round Back_b11;
extern TLabel Label390;
extern TImage Down_21_;
extern TImage Down_20_;
extern TImage Down_19_;
extern TImage Down_22_;
extern TImage Down_23_;
extern TImage Up_22_;
extern TImage Up_21_;
extern TImage Up_20_;
extern TImage Up_19_;
extern TImage Up_23_;
extern TImage Set_22_;
extern TImage Set_21_;
extern TImage Set_20_;
extern TImage Set_19_;
extern TImage Set_23_;
extern TButton_Round * const code Screen15_Buttons_Round[8];
extern TLabel * const code Screen15_Labels[2];
extern TImage * const code Screen15_Images[31];
extern TCircleButton * const code Screen15_CircleButtons[1];

extern TScreen DEVICES;
extern TCImage Image390;
extern TImage Image1;
extern TImage Image4;
extern TImage Image98;
extern TImage Image94;
extern TImage Image68;
extern TImage Image67;
extern TImage Image66;
extern TImage Image65;
extern TImage Image64;
extern TImage Image36;
extern TImage Image35;
extern TImage Image19;
extern TImage Image9;
extern TImage Image8;
extern TImage D_Source_1;
extern TImage D_Heating_1;
extern TImage D_Reverse_1;
extern TImage D_Compr_1;
extern TImage D_DHW;
extern TLabel Device_label;
extern TImage D_Electric;
extern TImage D_GAZ;
extern TImage D_Compr_2;
extern TImage D_Source_2;
extern TImage D_Heating_2;
extern TImage D_Reverse_2;
extern TImage D_Solar;
extern TImage D_fan2;
extern TImage D_fan1;
extern TLabel Pump1;
extern TLabel Pump2;
extern TLabel Revers1;
extern TLabel Compr_1;
extern TLabel Valve_1;
extern TLabel Label59;
extern TLabel Label62;
extern TLabel Label64;
extern TLabel Label65;
extern TLabel Label67;
extern TLabel Label68;
extern TButton_Round Home_b15;
extern TLabel Electricobject_TatDiagram;
extern TButton_Round * const code Screen16_Buttons_Round[1];
extern TLabel * const code Screen16_Labels[13];
extern TImage * const code Screen16_Images[28];
extern TCImage * const code Screen16_CImages[1];

extern TScreen Graph;
extern TImage Image37;
extern TBox Box23;
extern TLine Line1;
extern TLine Line2;
extern TLine Line3;
extern TLine Line8;
extern TLine Line9;
extern TLine Line10;
extern TLine Line11;
extern TLine Line12;
extern TLabel graph1_pos;
extern TLabel Label83;
extern TLabel Label84;
extern TLabel Label85;
extern TLabel Label86;
extern TLabel Label87;
extern TLabel Label88;
extern TLabel Label89;
extern TLabel Label90;
extern TLabel Label91;
extern TLabel Label92;
extern TLabel Label93;
extern TLine Line4;
extern TLine Line5;
extern TLine Line6;
extern TLabel Label47;
extern TLabel Label94;
extern TLine Line7;
extern TImage Image269;
extern TLabel GraphTimelabel;
extern TLabel Graph_Label;
extern TButton_Round graph_br1_in;
extern TButton_Round graph_br1_out;
extern TButton_Round graph_heat1_in;
extern TButton_Round graph_heat1_out;
extern TButton_Round Home_b16;
extern TButton_Round Next_b8;
extern TButton_Round Back_b12;
extern TCircleButton CircleButton11;
extern TLabel Label377;
extern TLabel Label378;
extern TLabel Label380;
extern TLabel Label381;
extern TLabel Label382;
extern TButton_Round * const code Screen17_Buttons_Round[7];
extern TLabel * const code Screen17_Labels[21];
extern TImage * const code Screen17_Images[2];
extern TCircleButton * const code Screen17_CircleButtons[1];
extern TBox * const code Screen17_Boxes[1];
extern TLine * const code Screen17_Lines[12];

extern TScreen Schema1;
extern TImage Image69;
extern TImage Image71;
extern TLabel Label42;
extern TImage Image73;
extern TImage Image74;
extern TImage Image75;
extern TImage Image76;
extern TImage Image77;
extern TImage Image79;
extern TButton S_Brine_In_1;
extern TButton S_Brine_Out_1;
extern TButton S_Heat_Out_1;
extern TButton S_Heat_In_1;
extern TButton Sens_DHW;
extern TButton S_tank;
extern TButton S_ComprEx_1;
extern TButton S_High_Press_1;
extern TButton S_Low_Press_1;
extern TButton S_SH_1;
extern TImage Image78;
extern TImage Image80;
extern TButton flow_source;
extern TButton flow_heat;
extern TImage Image117;
extern TImage Image118;
extern TImage Image119;
extern TImage Image120;
extern TImage Image124;
extern TImage Image126;
extern TImage Image127;
extern TImage Image131;
extern TButton flow_sun;
extern TButton draw_One_ground_back;
extern TButton * const code Screen18_Buttons[14];
extern TLabel * const code Screen18_Labels[1];
extern TImage * const code Screen18_Images[18];

extern TScreen MODE;
extern TImage Image41;
extern TImage Power_220V;
extern TLabel Label239;
extern TImage Two_Compressors;
extern TImage Reversing_Heat_OFF;
extern TImage Flow_Source_sensor_OFF;
extern TImage Flow_Source_Heat1_OFF;
extern TImage Flow_Source_Heat2_OFF;
extern TImage One_Compressors;
extern TImage Reversing_ON_HEAT;
extern TImage Flow_Source__Sensor_ON;
extern TImage Flow_Source__Heat1_ON;
extern TImage Flow_Source__Heat2_ON;
extern TImage Power_380V;
extern TButton_Round Home_b17;
extern TButton_Round Next_b9;
extern TButton_Round Back_13;
extern TCircleButton CircleButton12;
extern TButton_Round * const code Screen19_Buttons_Round[3];
extern TLabel * const code Screen19_Labels[1];
extern TImage * const code Screen19_Images[13];
extern TCircleButton * const code Screen19_CircleButtons[1];

extern TScreen FURNANCE;
extern TImage Image43;
extern TImage Image140;
extern TImage Image150;
extern TImage Image136;
extern TImage Image137;
extern TImage Image151;
extern TImage Image191;
extern TImage Image190;
extern TImage Image148;
extern TImage Image149;
extern TImage Image189;
extern TImage Image188;
extern TImage Image143;
extern TLabel Label63;
extern TImage Image152;
extern TImage furnance_time_ON;
extern TImage Furnance_start_temp_Down;
extern TImage Furnance_off_down;
extern TImage Furnance_time_down;
extern TImage Furnance_start_temp_UP;
extern TImage Furnance_HP_OFF_UP;
extern TImage Furnance_off_up;
extern TImage Furnance_time_up;
extern TImage Furnance_HP_OFF_Dowm;
extern TImage furnance_time_OFF;
extern TImage furnance_Mode_on;
extern TBox Box14;
extern TBox Box15;
extern TButton_Round Home_b18;
extern TButton_Round Back_b14;
extern TButton_Round Furnance_temperature_ON;
extern TButton_Round heat_pump_OFF;
extern TButton_Round furnance_OFF;
extern TButton_Round furnance_Timer;
extern TImage Furnance_off_save;
extern TImage Furnance_HP_OFF_save;
extern TButton_Round * const code Screen20_Buttons_Round[6];
extern TLabel * const code Screen20_Labels[1];
extern TImage * const code Screen20_Images[27];
extern TBox * const code Screen20_Boxes[2];

extern TScreen Ethernet;
extern TImage Image107;
extern TBox Box7;
extern TBox Box8;
extern TBox Box9;
extern TBox Box10;
extern TLabel IPAddressLabel;
extern TLabel MaskLabel;
extern TLabel GATELabel;
extern TLabel DNSLabel;
extern TButton_Round LANSet;
extern TButton_Round SetGateWay;
extern TButton_Round SetDNS;
extern TButton_Round SetIPAddress;
extern TButton_Round SetMask;
extern TButton_Round LAN_Key_1;
extern TButton_Round LAN_Key_2;
extern TButton_Round LAN_Key_3;
extern TButton_Round LAN_Key_4;
extern TButton_Round LAN_Key_5;
extern TButton_Round LAN_Key_6;
extern TButton_Round LAN_Key_7;
extern TButton_Round LAN_Key_8;
extern TButton_Round LAN_Key_9;
extern TButton_Round LAN_Key_0;
extern TLabel Label40;
extern TButton_Round LAN_Key_Dot;
extern TButton_Round LAN_Key_Clear;
extern TButton_Round Home_b19;
extern TButton_Round Back_b15;
extern TButton_Round * const code Screen21_Buttons_Round[19];
extern TLabel * const code Screen21_Labels[5];
extern TImage * const code Screen21_Images[1];
extern TBox * const code Screen21_Boxes[4];

extern TScreen SETTINGS;
extern TImage Image146;
extern TImage Image109;
extern TImage Image147;
extern TImage Image153;
extern TLabel Label44;
extern TImage Image114;
extern TImage Image115;
extern TImage Image116;
extern TImage Image121;
extern TImage Image122;
extern TImage Image123;
extern TImage Image128;
extern TImage Image129;
extern TImage Image130;
extern TImage Image135;
extern TImage Image138;
extern TImage Set_DHW_HY;
extern TImage Hyst_Heat_down;
extern TImage Hyst_DHW_down;
extern TImage Hyst_Heat_up;
extern TImage Hyst_Cool_up;
extern TImage Hyst_DHW_up;
extern TImage Hyst_Cool_down;
extern TButton_Round Home_b20;
extern TButton_Round Back_b16;
extern TButton_Round Hysteresis_heating;
extern TButton_Round Hysteresis_cooling;
extern TButton_Round Hysteresis_DHW;
extern TButton_Round * const code Screen22_Buttons_Round[5];
extern TLabel * const code Screen22_Labels[1];
extern TImage * const code Screen22_Images[22];

extern TScreen Gauge2;
extern TImage Image62;
extern TLabel Label69;
extern TImage Image134;
extern TImage HP2_gauge;
extern TImage LP2_gauge;
extern TLine HP2_arrow;
extern TLine LP2_arrow;
extern TButton_Round Home_b22;
extern TButton_Round Back_b18;
extern TCircleButton CircleButton15;
extern TButton_Round * const code Screen23_Buttons_Round[2];
extern TLabel * const code Screen23_Labels[1];
extern TImage * const code Screen23_Images[4];
extern TCircleButton * const code Screen23_CircleButtons[1];
extern TLine * const code Screen23_Lines[2];

extern TScreen Sensor2;
extern TImage Image142;
extern TLabel Module2_br_outlet;
extern TLabel Label81;
extern TLabel Module2_heat_inlet;
extern TLabel Module2_heat_outlet;
extern TLabel Module2_compressor;
extern TLabel Module2_SH;
extern TLabel Module2_SC;
extern TButton_Round S_Brine_Inlet_2;
extern TButton_Round S_Brine_Outlet_2;
extern TButton_Round S_Heat_Inlet_2;
extern TButton_Round S_Heat_Outlet_2;
extern TButton_Round S_Compressor_2;
extern TButton_Round S_Superheat_2;
extern TButton_Round S_Subcool_2;
extern TLabel Label100;
extern TLabel Label101;
extern TLabel Label102;
extern TLabel Label103;
extern TLabel Label105;
extern TLabel Label106;
extern TLabel Label107;
extern TLabel Label108;
extern TLabel Label109;
extern TLabel Label110;
extern TLabel Label111;
extern TLabel Label112;
extern TLabel Label113;
extern TLabel Label114;
extern TLabel Label115;
extern TLabel Label116;
extern TLabel Module2_br_flow;
extern TButton_Round S_Source_Flow_2;
extern TLabel Module2_heat_flow;
extern TButton_Round S_Heat_Flow_2;
extern TLabel Label119;
extern TLabel Label120;
extern TLabel Label128;
extern TLabel Label129;
extern TLabel Label76;
extern TButton_Round S_condenser_2;
extern TButton_Round S_suction_2;
extern TLabel Module2_cond;
extern TLabel Module2_suct;
extern TButton_Round ButtonRound14;
extern TButton_Round Home_b23;
extern TCircleButton CircleButton16;
extern TButton_Round S_Low_Pressure_2;
extern TButton_Round S_High_Pressure_2;
extern TLabel Label283;
extern TLabel Label284;
extern TLabel Label3;
extern TLabel Label26;
extern TButton_Round * const code Screen24_Buttons_Round[15];
extern TLabel * const code Screen24_Labels[36];
extern TImage * const code Screen24_Images[1];
extern TCircleButton * const code Screen24_CircleButtons[1];

extern TScreen MODE2;
extern TImage Image157;
extern TLabel Label80;
extern TImage Mode_air_on;
extern TImage Mode_ground_on;
extern TButton_Round Home_b24;
extern TButton_Round Back_20;
extern TCircleButton CircleButton13;
extern TButton_Round * const code Screen25_Buttons_Round[2];
extern TLabel * const code Screen25_Labels[1];
extern TImage * const code Screen25_Images[3];
extern TCircleButton * const code Screen25_CircleButtons[1];

extern TScreen Schema2;
extern TImage Image159;
extern TImage Image273;
extern TImage Image162;
extern TImage Image176;
extern TImage Image174;
extern TImage Image166;
extern TImage Image276;
extern TImage Image175;
extern TImage Image274;
extern TImage Image267;
extern TImage Image164;
extern TImage Image270;
extern TImage Image165;
extern TLabel Label82;
extern TImage Image203;
extern TButton Module1_br_inlet;
extern TButton Module1_br_outlet;
extern TButton Module1_heat_outlet;
extern TButton Module1_heat_inlet;
extern TButton TANK;
extern TButton DHW;
extern TButton Module1_exhaust;
extern TButton Module1_superheat;
extern TButton Module1_heat_flow;
extern TImage Image181;
extern TImage Image160;
extern TButton Button7;
extern TButton Button9;
extern TButton Button10;
extern TButton Button11;
extern TButton Module2_exhaust;
extern TButton Module2_superheat;
extern TButton Module2_brine_flow;
extern TButton Button15;
extern TImage Image178;
extern TImage Image183;
extern TImage Image271;
extern TImage Image272;
extern TImage Image172;
extern TImage Image182;
extern TImage Image204;
extern TImage Image180;
extern TImage Image275;
extern TImage Image202;
extern TLabel Label95;
extern TButton Button13;
extern TButton Button5;
extern TButton * const code Screen26_Buttons[19];
extern TLabel * const code Screen26_Labels[2];
extern TImage * const code Screen26_Images[26];

extern TScreen SYSTEM_EVENTS2;
extern TImage Image278;
extern TLabel Label96;
extern TButton_Round Time2_reverse;
extern TButton_Round Time2_ground_pump;
extern TButton_Round Time2_heat_pump;
extern TButton_Round Time2_compressor;
extern TButton_Round Home_b25;
extern TButton_Round Time_solar;
extern TCircleButton CircleButton7;
extern TButton_Round Back_b21;
extern TLabel Label9;
extern TButton_Round * const code Screen27_Buttons_Round[7];
extern TLabel * const code Screen27_Labels[2];
extern TImage * const code Screen27_Images[1];
extern TCircleButton * const code Screen27_CircleButtons[1];

extern TScreen AIR_TWO;
extern TImage Image289;
extern TImage Image324;
extern TImage Image290;
extern TImage Image297;
extern TImage Image296;
extern TImage Image326;
extern TImage Image327;
extern TImage Image330;
extern TImage Image329;
extern TImage Image325;
extern TImage Image291;
extern TLabel Label97;
extern TImage Image303;
extern TLabel Label98;
extern TImage Image301;
extern TImage Image318;
extern TImage Image320;
extern TImage Image328;
extern TImage Image331;
extern TImage Image322;
extern TImage Image321;
extern TImage Image332;
extern TImage Image323;
extern TImage Image292;
extern TImage Image293;
extern TImage Image305;
extern TImage Image319;
extern TButton Button17;
extern TButton Button18;
extern TButton Button19;
extern TButton Button20;
extern TButton Button22;
extern TButton Button23;
extern TButton Button25;
extern TButton Button28;
extern TButton Button29;
extern TButton Button30;
extern TButton Button31;
extern TButton Button33;
extern TButton Button34;
extern TButton Button16;
extern TImage Image299;
extern TButton Button6;
extern TButton * const code Screen28_Buttons[15];
extern TLabel * const code Screen28_Labels[2];
extern TImage * const code Screen28_Images[26];

extern TScreen AIR_ONE;
extern TImage Image333;
extern TImage Image336;
extern TImage Image339;
extern TImage Image338;
extern TImage Image343;
extern TImage Image342;
extern TImage Image341;
extern TImage Image352;
extern TImage Image334;
extern TLabel Label99;
extern TImage Image358;
extern TImage Image360;
extern TImage Image362;
extern TImage Image365;
extern TImage Image367;
extern TImage Image368;
extern TImage Image361;
extern TImage Image340;
extern TImage Image337;
extern TButton Button14;
extern TButton Button26;
extern TButton Button27;
extern TButton Button32;
extern TButton Button35;
extern TButton Button36;
extern TButton Button37;
extern TButton Button38;
extern TButton Button39;
extern TButton Button41;
extern TButton Button42;
extern TButton Button2;
extern TButton * const code Screen29_Buttons[12];
extern TLabel * const code Screen29_Labels[1];
extern TImage * const code Screen29_Images[18];

extern TScreen GRAPH2;
extern TImage Image374;
extern TBox Box28;
extern TLine Line13;
extern TLine Line14;
extern TLine Line15;
extern TLine Line17;
extern TLine Line18;
extern TLine Line19;
extern TLine Line20;
extern TLine Line21;
extern TLabel Label121;
extern TLabel Label122;
extern TLabel Label125;
extern TLabel Label127;
extern TLabel Label130;
extern TLabel Label131;
extern TLabel Label132;
extern TLabel Label133;
extern TLabel Label134;
extern TLabel Label135;
extern TLabel Label136;
extern TLine Line22;
extern TLine Line23;
extern TLine Line24;
extern TLabel Label137;
extern TLabel Label146;
extern TLine Line25;
extern TImage Image378;
extern TLabel Label151;
extern TLabel _;
extern TButton_Round Home_b26;
extern TButton_Round Back_b22;
extern TLabel graph2_pos;
extern TButton_Round graph_br2_in;
extern TButton_Round graph_br2_out;
extern TButton_Round graph_heat2_in;
extern TButton_Round graph_heat2_out;
extern TLabel Label5;
extern TLabel Label8;
extern TLabel Label16;
extern TLabel Label19;
extern TLabel Label21;
extern TCircleButton CircleButton5;
extern TButton_Round * const code Screen30_Buttons_Round[6];
extern TLabel * const code Screen30_Labels[21];
extern TImage * const code Screen30_Images[2];
extern TCircleButton * const code Screen30_CircleButtons[1];
extern TBox * const code Screen30_Boxes[1];
extern TLine * const code Screen30_Lines[12];

extern TScreen TIMERS;
extern TImage Image133;
extern TImage Image395;
extern TImage Image393;
extern TImage Image161;
extern TImage Image295;
extern TImage Image376;
extern TImage Image391;
extern TImage Image111;
extern TImage Image402;
extern TImage Image403;
extern TImage Image405;
extern TImage Image404;
extern TImage Image406;
extern TImage Image113;
extern TLabel Label162;
extern TButton_Round Home_b27;
extern TButton_Round Back_b23;
extern TButton_Round * const code Screen31_Buttons_Round[2];
extern TLabel * const code Screen31_Labels[1];
extern TImage * const code Screen31_Images[14];

extern TScreen ENERGY;
extern TImage Image108;
extern TLabel Label126;
extern TButton_Round Home_b28;
extern TButton_Round Back_b24;
extern TButton_Round Energy_Volt_1;
extern TLabel Label251;
extern TLabel Label252;
extern TButton_Round S_Current_1;
extern TLabel Label253;
extern TButton_Round Energy_Volt_2;
extern TLabel Label254;
extern TLabel Label255;
extern TButton_Round S_Current_2;
extern TLabel Label256;
extern TButton_Round Energy_Volt_3;
extern TLabel Label257;
extern TLabel Label258;
extern TButton_Round S_Current_3;
extern TLabel Label259;
extern TButton_Round Energy_Power_1;
extern TLabel Label260;
extern TLabel Label261;
extern TButton_Round ButtonRound12;
extern TLabel Label400;
extern TLabel Label401;
extern TButton_Round * const code Screen32_Buttons_Round[10];
extern TLabel * const code Screen32_Labels[14];
extern TImage * const code Screen32_Images[1];

extern TScreen DEFROST;
extern TImage Image82;
extern TImage Image388;
extern TImage Defrost_set4;
extern TImage Image355;
extern TImage Image198;
extern TImage Image199;
extern TButton_Round Defrost_on_time;
extern TImage Image377;
extern TImage Image379;
extern TImage Image382;
extern TImage Image383;
extern TImage Image381;
extern TImage Image384;
extern TButton_Round Defrost_off_time;
extern TButton_Round Defrost_on_temperature;
extern TButton_Round Defrost_off_temperature;
extern TButton_Round Home_b29;
extern TButton_Round Back_b25;
extern TImage Defrost_minus1;
extern TImage Defrost_minus2;
extern TImage Defrost_minus3;
extern TImage Defrost_plus1;
extern TImage Defrost_plus2;
extern TImage Defrost_plus3;
extern TImage Defrost_set1;
extern TImage Defrost_set2;
extern TImage Defrost_set3;
extern TImage Image386;
extern TImage Image387;
extern TImage Defrost_plus4;
extern TImage Defrost_minus4;
extern TButton_Round Defrost_on_humidity;
extern TImage Image47;
extern TImage Image70;
extern TImage Image103;
extern TLabel Label51;
extern TImage humidity_down;
extern TImage humidity_up;
extern TImage humidity_set;
extern TButton_Round ButtonRound2;
extern TButton_Round * const code Screen33_Buttons_Round[8];
extern TLabel * const code Screen33_Labels[1];
extern TImage * const code Screen33_Images[31];

extern TScreen EVENTS;
extern TImage Image63;
extern TButton_Round Home_b30;
extern TBox_Round BoxRound1;
extern TButton_Round Back_b26;
extern TLabel Label50;
extern TButton_Round * const code Screen34_Buttons_Round[2];
extern TLabel * const code Screen34_Labels[1];
extern TImage * const code Screen34_Images[1];
extern TBox_Round * const code Screen34_Boxes_Round[1];

extern TScreen LIMITS5;
extern TImage Image21;
extern TImage Image22;
extern TImage Image29;
extern TImage Image280;
extern TImage Image99;
extern TImage Image100;
extern TImage Image281;
extern TButton_Round Home_b31;
extern TButton_Round Set_max_low_pressure;
extern TButton_Round Set_min_low_pressure;
extern TImage Image12;
extern TImage Image14;
extern TImage Image17;
extern TImage Image18;
extern TImage Image282;
extern TImage Image279;
extern TButton_Round Back_b27;
extern TLabel Label46;
extern TCircleButton CircleButton3;
extern TImage Set_phase_off;
extern TImage Set_voltage_off;
extern TImage Set_voltage_on;
extern TImage Set_phase_on;
extern TImage Image5;
extern TImage Image6;
extern TImage Image46;
extern TImage UP_26_;
extern TImage Set_26_;
extern TButton_Round Set_eev_on;
extern TImage Image7;
extern TButton_Round * const code Screen35_Buttons_Round[5];
extern TLabel * const code Screen35_Labels[1];
extern TImage * const code Screen35_Images[23];
extern TCircleButton * const code Screen35_CircleButtons[1];

extern TScreen MICRO_SD;
extern TImage Image2;
extern TButton_Round Back_b28;
extern TButton_Round Home_b32;
extern TLabel Label7;
extern TButton_Round * const code Screen36_Buttons_Round[2];
extern TLabel * const code Screen36_Labels[1];
extern TImage * const code Screen36_Images[1];

extern TScreen LIMITS3;
extern TImage Image461;
extern TImage Image469;
extern TImage Image471;
extern TImage Image472;
extern TImage Image473;
extern TImage Image470;
extern TImage Image468;
extern TImage Image482;
extern TImage Image474;
extern TImage Image478;
extern TImage Image479;
extern TImage Image475;
extern TImage Image483;
extern TImage Image484;
extern TImage Image476;
extern TImage Image480;
extern TImage Image481;
extern TImage Image477;
extern TImage Image485;
extern TButton_Round Home_b33;
extern TButton_Round Back_b29;
extern TButton_Round Next_b10;
extern TImage Down_15_;
extern TImage Down_16_;
extern TImage Down_17_;
extern TImage Down_18_;
extern TImage Up_15_;
extern TImage Up_16_;
extern TImage Up_17_;
extern TImage Up_18_;
extern TImage Set_15_;
extern TImage Set_16_;
extern TImage Set_17_;
extern TImage Set_18_;
extern TImage Set_14_;
extern TImage Set_13_;
extern TImage Up_14_;
extern TImage Up_13_;
extern TImage Down_14_;
extern TImage Down_13_;
extern TButton_Round Set_Furnance_one_preset;
extern TButton_Round Set_solar_max;
extern TButton_Round Set_max_electric;
extern TButton_Round Set_max_furnance;
extern TButton_Round Set_electric_preset;
extern TButton_Round Set_min_superheat;
extern TLabel Label341;
extern TCircleButton CircleButton17;
extern TButton_Round * const code Screen37_Buttons_Round[9];
extern TLabel * const code Screen37_Labels[1];
extern TImage * const code Screen37_Images[37];
extern TCircleButton * const code Screen37_CircleButtons[1];



void BackToHome();
void goToBack();
void nextPage();

void Main_OFFOnClick();
void bar_heatingOnClick();
void DHW_SetingOnClick();
void Heat_SettingOnClick();
void Click_HEAT();
void Click_DHW();
void MainBut1OnUp();
void MainBut1OnPress();
void MainBut2OnUp();
void MainBut2OnPress();
void MainBut3OnUp();
void MainBut3OnPress();
void MainBut4OnUp();
void MainBut4OnPress();
void MainBut5OnUp();
void MainBut5OnPress();
void DHW_UPOnClick();
void DHW_DOWNOnClick();
void HEAT_UPOnClick();
void HEAT_DownOnClick();

void user_settingOnUp();
void user_settingOnPress();
void user_set_timeOnPress();
void user_set_timeOnUp();
void user_check_temperatureOnPress();
void user_check_temperatureOnUp();
void user_set_LANOnPress();
void user_set_LANOnUp();
void user_check_errorsOnPress();
void user_check_errorsOnUp();
void user_set_timersOnPress();
void user_set_timersOnUp();
void user_hysterezisOnPress();
void user_hysterezisOnUp();
void User_history_checkOnPress();
void User_history_checkOnUp();
void user_energyOnUp();
void user_energyOnPress();
void admin_set_systemOnUp();
void admin_set_systemOnPress ();
void furnanceUP();
void furnanceDown();
void user_defrostOnUp();
void user_defrostOnPress();
#line 2030 "c:/users/dumitru/desktop/dima/alta_2_compressor_display/controller_code/mikroc pro for arm/controller_objects.h"
void DEC_EEV1OnPress();
void INC_EEV1OnPress();

void Set_Trv();

void _1OnClick() ;
void _2OnClick() ;
void _3OnClick() ;
void _4OnClick() ;
void _5OnClick() ;
void _6OnClick() ;
void _7OnClick() ;
void _8OnClick() ;
void _9OnClick() ;
void _0OnClick() ;
void _QOnClick() ;
void _WOnClick() ;
void _EOnClick() ;
void _ROnClick() ;
void _TOnClick() ;
void _YOnClick() ;
void _UOnClick() ;
void _IOnClick() ;
void _OOnClick() ;
void _POnClick() ;
void _AOnClick() ;
void _SOnClick() ;
void _DOnClick() ;
void _FOnClick() ;
void _GOnClick() ;
void _HOnClick() ;
void _JOnClick() ;
void _KOnClick() ;
void _LOnClick() ;
void _ZOnClick() ;
void _XOnClick() ;
void _COnClick() ;
void _VOnClick() ;
void _BOnClick() ;
void _NOnClick() ;
void _MOnClick() ;
void _CommaOnClick();
void _ColonOnClick() ;
void _SlashOnClick() ;
void _DELOnClick() ;
void ClearOnPress() ;
void CAPS_SwitchOnClick();
void SPACEOnClick();
void ENTEROnClick() ;

void SetDateAndTimeOnClick();
void OneYearUpOnClick();
void OneYearDwnOnClick();
void OneYearUpOnUp();
void OneYearUpOnPress();
void OneYearDwnOnUp();
void OneYearDwnOnPress();
void TenYearUpOnClick();
void TenYearDwnOnClick();
void TenYearUpOnUp();
void TenYearDwnOnUp();
void TenYearDwnOnPress();
void TenYearUpOnPress();
void OneYearUpOnClick();
void OneYearDwnOnClick();
void OneYearUpOnUp();
void OneYearUpOnPress();
void OneYearDwnOnUp();
void OneYearDwnOnPress();
void MonthDateUpOnClick();
void MonthDateUpOnUp();
void MonthDateUpOnPress();
void MonthDateDwnOnClick();
void MonthDateDwnOnUp();
void MonthDateDwnOnPress();
void TenDayUpOnClick();
void TenDayDwnOnClick();
void TenDayUpOnUp();
void TenDayDwnOnUp();
void TenDayUpOnPress();
void TenDayDwnOnPress();
void OneDayUpOnClick();
void OneDayDwnOnClick();
void OneDayUpOnUp();
void OneDayDwnOnUp();
void OneDayUpOnPress();
void OneDayDwnOnPress();
void Day_unitUpOnClick();
void Day_unitDwnOnClick();
void Day_unitUpOnUp() ;
void Day_unitDwnOnUp() ;
void Day_unitUpOnPress();
void Day_unitDwnOnPress();
void Unit_hoursUpOnClick();
void Unit_hoursDwnOnClick();
void Unit_hoursUpOnUp();
void Unit_hoursDwnOnUp();
void Unit_hoursUpOnPress();
void Unit_hoursDwnOnPress();
void Ten_minutesUpOnClick();
void Ten_minutesDwnOnClick();
void Ten_minutesUpOnUp();
void Ten_minutesDwnOnUp();
void Ten_minutesUpOnPress();
void Ten_minutesDwnOnPress();
void Unit_minutesUpOnClick();
void Unit_minutesDwnOnClick();
void Unit_minutesUpOnUp();
void Unit_minutesDwnOnUp();
void Unit_minutesUpOnPress();
void Unit_minutesDwnOnPress();

 void Admin_SetOnClick();

void system_passOnDown();
void system_passOnUp() ;
void ModeSetOnUp();
void ModeSetOnDown();
void system_EEVOnDown() ;
void system_EEVOnUp();
void system_modeOnDown();
void system_modeOnUp();
void system_delayOnDown();
void system_delayOnUp();
void system_graphOnDown();
void system_graphOnUp() ;
void system_microSDOnDown();
void system_microSDOnUp();
void system_delayOnUp();
void system_limitsOnDown();
void system_limitsOnUp();
void ssytem_graphOnDown();
void ssytem_graphOnUp();
void system_historyOnDown();
void system_historyOnUp();


void Delay_Source_DOWNOnUp();
void Delay_Source_DOWNOnPress();
void Delay_Source_UPOnUp();
void Delay_Source_UPOnPress();
void Delay_Source_SETOnUp();
void Delay_Source_SETOnDown();

void Delay_heat_pump_DOWNOnUp();
void Delay_heat_pump_DOWNOnPress();
void Delay_heat_pump_upOnUp();
void Delay_heat_pump_upOnPress();
void Delay_heat_pump_SETOnUp();
void Delay_heat_pump_SETOnDown();

void Delay_reversing_DOWNOnUp() ;
void Delay_reversing_DOWNOnPress() ;
void Delay_reversing_UPOnUp() ;
void Delay_reversing_UPOnPress() ;
void Delay_reversing_SETOnUp();
void Delay_reversing_SETOnDown();

void Delay_trv_DOWNOnUp() ;
void Delay_trv_DOWNOnPress();
void Delay_trv_UPOnPress() ;
void Delay_trv_UPOnUp();
void Delay_EEV_SETOnUp();
void Delay_EEV_SETOnDown() ;

void Delay_DHW_valve_DOWNOnUp() ;
void Delay_DHW_valve_DOWNOnPress() ;
void Delay_DHW_valve_UPOnUp() ;
void Delay_DHW_valve_UPOnPress();
void Delay_DHW_valve_SETOnUp();
void Delay_DHW_valve_SETOnDown() ;

void Delay_compressor_DOWNOnUp();
void Delay_compressor_DOWNOnPress() ;
void Delay_compressor_UPOnUp() ;
void Delay_compressor_UPOnPress() ;
void Delay_compressor_SETOnUp() ;
void Delay_compressor_SETOnDown();
void Delay_trv_SETOnUp();
void Delay_trv_OnPress();

void Down_1_OnUp() ;
void Down_1_OnPress();
void Up_1_OnUp() ;
void Up_1_OnPress() ;
void Down_2_OnUp() ;
void Down_2_OnPress();
void Up_2_OnPress() ;
void Up_2_OnUp() ;
void Down_3_OnPress();
void Down_3_OnUp() ;
void Up_3_OnPress();
void Up_3_OnUp() ;
void Down_4_OnPress();
void Down_4_OnUp() ;
void Up_4_OnUp() ;
void Up_4_OnPress();
void Down_5_OnUp() ;
void Down_5_OnPress();
void Up_5_OnPress() ;
void Up_5_OnUp() ;
void Down_6_OnPress();
void Down_6_OnUp() ;
void Up_6_OnPress();
void Up_6_OnUp();
void Set_1_OnDown();
void Set_1_OnUp() ;
void Set_2_OnDown();
void Set_2_OnUp();
void Set_3_OnDown();
void Set_3_OnUp() ;
void Set_4_OnDown() ;
void Set_4_OnUp() ;
void Set_5_OnDown();
void Set_5_OnUp() ;
void Furnance_HP_OFF_save_ondown();
void Set_6_OnUp() ;
void Set_6_OnDown();

void Down_7_OnUp() ;
void Down_7_OnPress();
void Up_7_OnPress() ;
void Up_7_OnUp();
void Down_8_OnPress();
void Down_8_OnUp();
void Up_8_OnPress();
void Up_8_OnUp();
void Down_9_OnPress();
void Down_9_OnUp();
void Up_9_OnPress();
void Up_9_OnUp();
void Down_10_OnPress();
void Down_10_OnUp();
void Up_10_OnPress();
void Up_10_OnUp();
void Down_11_OnPress();
void Down_11_OnUp();
void Up_11_OnPress();
void Up_11_OnUp() ;
void Down_12_OnPress();
void Down_12_OnUp() ;
void Up_12_OnPress();
void Up_12_OnUp() ;
void Set_7_OnUp() ;
void Set_7_OnDown();
void Set_8_OnDown();
void Set_8_OnUp() ;
void Set_9_OnUp();
void Set_9_OnDown() ;
void Set_10_OnDown();
void Set_10_OnUp() ;
void Set_11_OnDown();
void Set_11_OnUp() ;
void Set_12_OnDown();
void Set_12_OnUp();


void Down_19_OnPress();
void Down_19_OnUp() ;
void Up_19_OnPress();
void Up_19_OnUp();
void Down_20_OnPress();
void Down_20_OnUp();
void Up_20_OnPress();
void Up_20_OnUp();
void Down_21_OnPress();
void Down_21_OnUp();
void Up_21_OnPress();
void Up_21_OnUp();
void Down_22_OnPress();
void Down_22_OnUp();
void Up_22_OnPress();
void Up_22_OnUp();
void Down_23_OnPress();
void Down_23_OnUp();
void Up_23_OnPress();
void Up_23_OnUp();
void Set_19_OnUp();
void Set_19_OnDown();
void Set_20_OnDown();
void Set_20_OnUp();
void Set_21_OnDown();
void Set_21_OnUp();
void Set_22_OnDown();
void Set_22_OnUp();
void Set_23_OnDown();
void Set_23_OnUp();

void One_CompressorsOnClick();
void Reversing_ON_HEATOnClick();
void Flow_Source__Sensor_ONOnClick();
void Flow_Source__Heat1_ONOnClick();
void Flow_Source__Heat2_ONOnClick();
void Power_380VOnClick();

void furnance_Mode_onOnClick();
void Furnance_start_temp_DownOnUp();
void Furnance_start_temp_DownOnPress();
void Furnance_HP_OFF_DowmOnUp();
void Furnance_HP_OFF_DowmOnPress();
void Furnance_HP_OFF_UPOnUp();
void Furnance_HP_OFF_UPOnPress();
void Furnance_off_downOnUp();
void Furnance_off_downOnPress();
void Furnance_off_upOnUp() ;
void Furnance_off_upOnPress();
void Furnance_off_save_onup();
void Furnance_off_save_ondown();
void Furnance_time_downOnUp();
void Furnance_time_downOnPress();
void Furnance_time_upOnUp();
void Furnance_time_upOnPress();
void furnance_time_OFFOnClick();
void Furnance_HP_OFF_save_onup();
void Furnance_start_temp_UPOnUp();
void Furnance_start_temp_UPOnPress();


void SetIPAddressOnClick();
void SetMaskOnClick();
void SetDNSOnClick();
void LAN_Key_1OnClick();
void LAN_Key_2OnClick();
void LAN_Key_3OnClick();
void LAN_Key_4OnClick();
void LAN_Key_5OnClick();
void LAN_Key_6OnClick();
void LAN_Key_7OnClick();
void LAN_Key_8OnClick();
void LAN_Key_9OnClick();
void LAN_Key_0OnClick();
void LAN_Key_DotOnClick();
void LAN_Key_ClearOnClick();
void LANSetOnClick();
void SetGateWayOnClick();

void Hyst_Heat_downOnUp();
void Hyst_Heat_downOnPress();
void Hyst_Heat_upOnUp();
void Hyst_Heat_upOnPress();
void Hyst_Cool_downOnUp();
void Hyst_Cool_downOnPress() ;
void Hyst_Cool_upOnUp();
void Hyst_Cool_upOnPress();
void Hyst_DHW_downOnUp();
void Hyst_DHW_downOnPress();
void Hyst_DHW_upOnUp();
void Hyst_DHW_upOnPress();
void Set_heat_onup();
void Set_heat_OnDown();
void Set_cool_OnUp();
void Set_cool_OnDown();
void Set_dhw_OnUp();
void Set_dhw_OnDown();


void DEC_EEV2OnPress();
void INC_EEV2OnPress();
 void EEV2DownOnUp();
void EEV2DownOnDown();
void EEV2UpOnUp();
void EEV2UpOnDown();
void EEV2_AutoOnClick();

void Mode_ground_onOnClick ();





 void Up_24_OnPress();
void Down_24_OnPress();
void Down_24_OnUp();
void Up_24_OnUp();
void Down_25_OnPress();
void Down_25_OnUp();
void Up_25_OnPress();
void Up_25_OnUp();
void Down_26_OnPress();
void Down_26_OnUp();
void UP_26_OnPress();
void UP_26_OnUp();
void Set_24_OnDown();
void Set_24_OnUp();
void Set_25_OnDown();
void Set_25_OnUp();
void Set_26_OnDown();
void Set_26_OnUp();
void Set_phase_check();
void Set_voltage_check();

void Down_13_OnUp();
void Down_13_OnPress();
void Up_13_OnPress();
void Up_13_OnUp();
void Down_14_OnPress();
void Down_14_OnUp();
void Up_14_OnPress();
void Up_14_OnUp();
void Down_15_OnPress();
void Down_15_OnUp();
void Up_15_OnPress();
void Up_15_OnUp();
void Down_16_OnPress();
void Down_16_OnUp();
void Up_16_OnPress();
void Up_16_OnUp();
void Down_17_OnPress();
void Down_17_OnUp();
void Up_17_OnPress();
void Up_17_OnUp();
void Down_18_OnPress();
void Down_18_OnUp();
void Up_18_OnPress();
void Up_18_OnUp();
void Set_15_OnUp();
void Set_15_OnDown();
void Set_16_OnUp();
void Set_16_OnDown();
void Set_17_OnUp ();
void Set_17_OnDown();
void Set_18_OnUp();
void Set_18_OnDown();
void Set_14_OnDown();
void Set_14_OnUp();
void Set_13_OnUp();
void Set_13_OnDown();




void dec_def();
void time_def_dec();
void temp_on_dec();
void temp_off_dec();
void hum_dec();

void inc_def();
void time_def_inc();
void temp_on_inc();
void temp_off_inc();
void hum_inc();
void temp_off_set();
void temp_on_set();
void hum_set();
void SetUPttimDef();
void SetdownttimDef();
void Setdownintdef();
void Setupintdef();
void Setuptempdef();
void Setdowntempdef();
void Mode_ground_onOnClick ();
void pushDEF();




extern char BoxRound8_Caption[];
extern char Set_Heat_Box_Caption[];
extern char Set_Dhw_Box_Caption[];
extern char background_Caption[];
extern char Heat_Windows_Caption[];
extern char HEAT_button_redraw_Caption[];
extern char DHW_button_redraw_Caption[];
extern char DWN_Windows_Caption[];
extern char Brine_Windows_Caption[];
extern char Image20_Caption[];
extern char Wheater_Windows_Caption[];
extern char Image44_Caption[];
extern char Image61_Caption[];
extern char Main_ON_Caption[];
extern char Main_OFF_Caption[];
extern char DHW_Seting_Caption[];
extern char Label53_Caption[];
extern char Label38_Caption[];
extern char Label39_Caption[];
extern char Label4_Caption[];
extern char Label20_Caption[];
extern char Brine_Line_Caption[];
extern char Heat_Setting_Caption[];
extern char alarm_led_Caption[];
extern char radio_led_Caption[];
extern char bar_heating_Caption[];
extern char bar_DHW_Caption[];
extern char dhw_led_Caption[];
extern char heat_led_Caption[];
extern char Line16_Caption[];
extern char Label140_Caption[];
extern char Label141_Caption[];
extern char bar_weather_Caption[];
extern char Weather_Icon_Caption[];
extern char bar_brine_Caption[];
extern char Brine_Icon_Caption[];
extern char MainBut3_Caption[];
extern char MainBut4_Caption[];
extern char clock_icon_Caption[];
extern char microSD_icon_Caption[];
extern char radio_icon_Caption[];
extern char dhw_icon_Caption[];
extern char Label25_Caption[];
extern char cool_icon_Caption[];
extern char Image28_Caption[];
extern char dhw_celc_Caption[];
extern char dhw_point_Caption[];
extern char heat_point_Caption[];
extern char heat_celc_Caption[];
extern char TEMP_Setting_value_Caption[];
extern char DHW_Setting_value_Caption[];
extern char WiFi_on_icon_Caption[];
extern char Image163_Caption[];
extern char Image167_Caption[];
extern char Image168_Caption[];
extern char Image169_Caption[];
extern char Image26_Caption[];
extern char Image170_Caption[];
extern char DHW_UP_Caption[];
extern char DHW_DOWN_Caption[];
extern char HEAT_Down_Caption[];
extern char HEAT_UP_Caption[];
extern char ON_OFF_Heat_Cool_Caption[];
extern char ON_OFF_DHW_Caption[];
extern char Image25_Caption[];
extern char Image40_Caption[];
extern char Image87_Caption[];
extern char heat_icon_Caption[];
extern char MainBut1_Caption[];
extern char MainBut2_Caption[];
extern char MainBut5_Caption[];
extern char heatBox_Caption[];
extern char heat_temp_main_Caption[];
extern char BoxRound2_Caption[];
extern char dhw_temp_main_Caption[];
extern char BoxRound3_Caption[];
extern char sourse_temp_input_main_Caption[];
extern char BoxRound4_Caption[];
extern char sourse_temp_output_main_Caption[];
extern char BoxRound5_Caption[];
extern char weather_temp_main_Caption[];
extern char BoxRound6_Caption[];
extern char humedity_main_Caption[];
extern char BoxRound7_Caption[];
extern char prassure_main_Caption[];
extern char dhw_T_Caption[];
extern char heat_T_Caption[];
extern char sourc_out_TEMP_Caption[];
extern char sign_OUT_Caption[];
extern char sourc_in_T_Caption[];
extern char sign_IN_Caption[];
extern char dhw_dec_Caption[];
extern char heat_dec_Caption[];
extern char sourc_in_dec_Caption[];
extern char source_out_dec_Caption[];
extern char Messages_Box_Caption[];
extern char DateTime_Caption[];
extern char Image30_Caption[];
extern char Image105_Caption[];
extern char Image60_Caption[];
extern char Image51_Caption[];
extern char Image50_Caption[];
extern char Image49_Caption[];
extern char Image48_Caption[];
extern char Image39_Caption[];
extern char Image52_Caption[];
extern char Image56_Caption[];
extern char Image54_Caption[];
extern char Image55_Caption[];
extern char User_menu_label_Caption[];
extern char User_time_label_Caption[];
extern char User_c_label_Caption[];
extern char User_lan_label_Caption[];
extern char User_errors_label_Caption[];
extern char User_timers_label_Caption[];
extern char User_events_label_Caption[];
extern char User_energy_label_Caption[];
extern char User_furnance_label_Caption[];
extern char User_defrost_label_Caption[];
extern char Label77_Caption[];
extern char user_set_time_Caption[];
extern char user_check_temperature_Caption[];
extern char user_set_LAN_Caption[];
extern char user_check_errors_Caption[];
extern char user_set_timers_Caption[];
extern char User_history_check_Caption[];
extern char user_check_energy_Caption[];
extern char admin_set_system_Caption[];
extern char user_check_graph_Caption[];
extern char Image57_Caption[];
extern char user_defrost_Caption[];
extern char Home_b1_Caption[];
extern char user_hysterezis_Caption[];
extern char user_setting_Caption[];
extern char User_operational_label_Caption[];
extern char User_hysterezis_label_Caption[];
extern char User_system_label_Caption[];
extern char Image27_Caption[];
extern char Image173_Caption[];
extern char DEC_EEV1_Caption[];
extern char INC_EEV1_Caption[];
extern char Red_bar_Caption[];
extern char EEV1_set_step_label_Caption[];
extern char EEV1_label_Caption[];
extern char Home_b2_Caption[];
extern char Back_b2_Caption[];
extern char Next_b1_Caption[];
extern char EEV1_superheat_Caption[];
extern char EEV1_value_Caption[];
extern char CircleButton9_Caption[];
extern char ButtonRound1_Caption[];
extern char Image31_Caption[];
extern char _1_Caption[];
extern char _2_Caption[];
extern char _3_Caption[];
extern char _4_Caption[];
extern char _5_Caption[];
extern char _6_Caption[];
extern char _7_Caption[];
extern char _8_Caption[];
extern char _9_Caption[];
extern char _0_Caption[];
extern char _Q_Caption[];
extern char _W_Caption[];
extern char _E_Caption[];
extern char _R_Caption[];
extern char _T_Caption[];
extern char _Y_Caption[];
extern char _U_Caption[];
extern char _I_Caption[];
extern char _O_Caption[];
extern char _P_Caption[];
extern char _A_Caption[];
extern char _S_Caption[];
extern char _D_Caption[];
extern char _F_Caption[];
extern char _G_Caption[];
extern char _H_Caption[];
extern char _J_Caption[];
extern char _K_Caption[];
extern char _L_Caption[];
extern char _Z_Caption[];
extern char _X_Caption[];
extern char _C_Caption[];
extern char _V_Caption[];
extern char _B_Caption[];
extern char _N_Caption[];
extern char _M_Caption[];
extern char Clear_Caption[];
extern char CAPS_Switch_Caption[];
extern char SPACE_Caption[];
extern char Password_box_Caption[];
extern char Label23_Caption[];
extern char Admin_box_Caption[];
extern char Label24_Caption[];
extern char Keyboard_label_Caption[];
extern char _DEL_Caption[];
extern char _Colon_Caption[];
extern char _Comma_Caption[];
extern char _Slash_Caption[];
extern char ENTER_Caption[];
extern char Home_b3_Caption[];
extern char Image32_Caption[];
extern char Ten_minutesUp_Caption[];
extern char Ten_minutesDwn_Caption[];
extern char Unit_minutesUp_Caption[];
extern char Unit_minutesDwn_Caption[];
extern char SetDateAndTime_Caption[];
extern char Year_word_Caption[];
extern char Month_Word_Caption[];
extern char Day_word_Caption[];
extern char Hour_word_Caption[];
extern char Min_word_Caption[];
extern char Day_unitUp_Caption[];
extern char Day_unitDwn_Caption[];
extern char Unit_hoursUp_Caption[];
extern char Unit_hoursDwn_Caption[];
extern char OneDayUp_Caption[];
extern char OneDayDwn_Caption[];
extern char LineSlash_Caption[];
extern char TenDayUp_Caption[];
extern char TenDayDwn_Caption[];
extern char MonthDateUp_Caption[];
extern char MonthDateDwn_Caption[];
extern char TenYearUp_Caption[];
extern char TenYearDwn_Caption[];
extern char OneYearUp_Caption[];
extern char OneYearDwn_Caption[];
extern char Time_setting_label_Caption[];
extern char home_b4_Caption[];
extern char Back_b3_Caption[];
extern char Button1_Caption[];
extern char Button3_Caption[];
extern char Button4_Caption[];
extern char Button8_Caption[];
extern char Button12_Caption[];
extern char Button21_Caption[];
extern char Button24_Caption[];
extern char Button40_Caption[];
extern char Button43_Caption[];
extern char Image45_Caption[];
extern char Error_label_Caption[];
extern char Error_message_Caption[];
extern char Text_error_Caption[];
extern char Label2_Caption[];
extern char Home_b5_Caption[];
extern char Back_b4_Caption[];
extern char Image23_Caption[];
extern char Password_label_Caption[];
extern char Admin_Set_Caption[];
extern char Admin_text_Caption[];
extern char Home_b6_Caption[];
extern char Back_b5_Caption[];
extern char Image38_Caption[];
extern char LP1_gauge_Caption[];
extern char HP1_gauge_Caption[];
extern char HP_arrow_Caption[];
extern char Gauge_label_Caption[];
extern char LP_arrow_Caption[];
extern char Image104_Caption[];
extern char Home_b7_Caption[];
extern char Next_b2_Caption[];
extern char CircleButton8_Caption[];
extern char Image81_Caption[];
extern char Image300_Caption[];
extern char System_setting_label_Caption[];
extern char sys_access_Caption[];
extern char Label138_Caption[];
extern char Label139_Caption[];
extern char Label142_Caption[];
extern char Label143_Caption[];
extern char Label144_Caption[];
extern char Label145_Caption[];
extern char Image90_Caption[];
extern char Image91_Caption[];
extern char system_delay_Caption[];
extern char system_limits_Caption[];
extern char Label238_Caption[];
extern char System_Set_Message_Caption[];
extern char Image85_Caption[];
extern char Image92_Caption[];
extern char Image88_Caption[];
extern char Image93_Caption[];
extern char system_history_Caption[];
extern char Image89_Caption[];
extern char Image83_Caption[];
extern char system_EEV_Caption[];
extern char system_pass_Caption[];
extern char system_mode_Caption[];
extern char system_graph_Caption[];
extern char system_microSD_Caption[];
extern char Home_b8_Caption[];
extern char Back_b30_Caption[];
extern char delay_bgd_Caption[];
extern char Image306_Caption[];
extern char Image307_Caption[];
extern char Image308_Caption[];
extern char Image309_Caption[];
extern char Image314_Caption[];
extern char Image313_Caption[];
extern char Image312_Caption[];
extern char Image344_Caption[];
extern char Image345_Caption[];
extern char Image346_Caption[];
extern char Image315_Caption[];
extern char Image347_Caption[];
extern char Image348_Caption[];
extern char Image311_Caption[];
extern char Image310_Caption[];
extern char Image316_Caption[];
extern char Image317_Caption[];
extern char Image349_Caption[];
extern char Box63_Caption[];
extern char Box64_Caption[];
extern char Box66_Caption[];
extern char Delay_Source_UP_Caption[];
extern char Delay_heat_pump_up_Caption[];
extern char Delay_reversing_UP_Caption[];
extern char Delay_trv_up_Caption[];
extern char Delay_DHW_valve_UP_Caption[];
extern char Delay_compressor_UP_Caption[];
extern char Delay_Source_SET_Caption[];
extern char Delay_heat_pump_SET_Caption[];
extern char Delay_reversing_SET_Caption[];
extern char Delay_EEV_SET_Caption[];
extern char Delay_DHW_valve_SET_Caption[];
extern char Delay_compressor_SET_Caption[];
extern char Delay_setting_label_Caption[];
extern char Home_b9_Caption[];
extern char Back_b6_Caption[];
extern char Delay_Source_DOWN_Caption[];
extern char Delay_heat_pump_DOWN_Caption[];
extern char Delay_reversing_DOWN_Caption[];
extern char Delay_trv_DOWN_Caption[];
extern char Delay_DHW_valve_DOWN_Caption[];
extern char Delay_compressor_DOWN_Caption[];
extern char Delay_Source_Caption[];
extern char Delay_heat_pump_Caption[];
extern char Delay_reversing_Caption[];
extern char Delay_EEV_Caption[];
extern char Delay_DHW_valve_Caption[];
extern char Delay_compressor_Caption[];
extern char Image171_Caption[];
extern char Home_b10_Caption[];
extern char Back_b7_Caption[];
extern char Next_b3_Caption[];
extern char Time_source1_Caption[];
extern char Time_heat1_Caption[];
extern char Time_Electric_Caption[];
extern char Time_reversing1_Caption[];
extern char Time_compressor1_Caption[];
extern char Time_furnance_Caption[];
extern char total_time_label_Caption[];
extern char CircleButton6_Caption[];
extern char Label6_Caption[];
extern char Image102_Caption[];
extern char Image200_Caption[];
extern char Image205_Caption[];
extern char Image206_Caption[];
extern char Image207_Caption[];
extern char Image208_Caption[];
extern char Image209_Caption[];
extern char Image218_Caption[];
extern char Image219_Caption[];
extern char Image220_Caption[];
extern char Image221_Caption[];
extern char Image222_Caption[];
extern char Image223_Caption[];
extern char Image246_Caption[];
extern char Image247_Caption[];
extern char Image248_Caption[];
extern char Image249_Caption[];
extern char Image250_Caption[];
extern char Image251_Caption[];
extern char Down_1__Caption[];
extern char Down_2__Caption[];
extern char Down_3__Caption[];
extern char Down_4__Caption[];
extern char Down_5__Caption[];
extern char Down_6__Caption[];
extern char Up_1__Caption[];
extern char Up_2__Caption[];
extern char Up_3__Caption[];
extern char Up_4__Caption[];
extern char Up_5__Caption[];
extern char Up_6__Caption[];
extern char Set_1__Caption[];
extern char Set_2__Caption[];
extern char Set_3__Caption[];
extern char Set_4__Caption[];
extern char Set_5__Caption[];
extern char Set_6__Caption[];
extern char Set_min_heating_HP_Caption[];
extern char Set_max_heating_HP_Caption[];
extern char Set_max_exhaust_Caption[];
extern char Set_min_source_temp_Caption[];
extern char Set_max_source_temp_Caption[];
extern char Set_min_delta_heat_Caption[];
extern char Home_b11_Caption[];
extern char Back_b8_Caption[];
extern char Next_b4_Caption[];
extern char Settings1_label_Caption[];
extern char CircleButton1_Caption[];
extern char Image3_Caption[];
extern char Image186_Caption[];
extern char Image257_Caption[];
extern char Image256_Caption[];
extern char Image255_Caption[];
extern char Image254_Caption[];
extern char Image253_Caption[];
extern char Image252_Caption[];
extern char Image224_Caption[];
extern char Image225_Caption[];
extern char Image226_Caption[];
extern char Image227_Caption[];
extern char Image228_Caption[];
extern char Image229_Caption[];
extern char Image215_Caption[];
extern char Image214_Caption[];
extern char Image213_Caption[];
extern char Image212_Caption[];
extern char Image211_Caption[];
extern char Image210_Caption[];
extern char Down_8__Caption[];
extern char Down_10__Caption[];
extern char Down_11__Caption[];
extern char Down_9__Caption[];
extern char Down_12__Caption[];
extern char Up_8__Caption[];
extern char Up_10__Caption[];
extern char Up_11__Caption[];
extern char Up_9__Caption[];
extern char Up_12__Caption[];
extern char Set_8__Caption[];
extern char Set_10__Caption[];
extern char Set_11__Caption[];
extern char Set_9__Caption[];
extern char Set_12__Caption[];
extern char Set_max_delta_heat_Caption[];
extern char Set_min_delta_DHW_Caption[];
extern char Set_min_delta_source_Caption[];
extern char Set_max_source_delta_Caption[];
extern char Set_max_delta_DHW_Caption[];
extern char Set_preset_time_electric_Caption[];
extern char Down_7__Caption[];
extern char Up_7__Caption[];
extern char Set_7__Caption[];
extern char Home_b12_Caption[];
extern char Back_b9_Caption[];
extern char Next_b5_Caption[];
extern char Settings2_label_Caption[];
extern char CircleButton2_Caption[];
extern char Image380_Caption[];
extern char Sensors2_label_Caption[];
extern char Label285_Caption[];
extern char Label286_Caption[];
extern char Label287_Caption[];
extern char Label288_Caption[];
extern char Label289_Caption[];
extern char Label290_Caption[];
extern char Label293_Caption[];
extern char Label294_Caption[];
extern char S_Brine_Inlet_1_Caption[];
extern char S_Brine_Outlet_1_Caption[];
extern char S_Heat_Inlet_1_Caption[];
extern char S_Heat_Outlet_1_Caption[];
extern char S_Compressor_1_Caption[];
extern char S_DHW_Caption[];
extern char S_Superheat_1_Caption[];
extern char S_Subcool_1_Caption[];
extern char Label297_Caption[];
extern char Label298_Caption[];
extern char Label299_Caption[];
extern char Label300_Caption[];
extern char Label301_Caption[];
extern char Label302_Caption[];
extern char Label303_Caption[];
extern char Label304_Caption[];
extern char Label305_Caption[];
extern char Label306_Caption[];
extern char Label309_Caption[];
extern char Label310_Caption[];
extern char Label315_Caption[];
extern char Label316_Caption[];
extern char Label317_Caption[];
extern char Label318_Caption[];
extern char Label319_Caption[];
extern char S_Source_Flow_1_Caption[];
extern char Label320_Caption[];
extern char S_Heat_Flow_1_Caption[];
extern char Label321_Caption[];
extern char Label322_Caption[];
extern char SS_tank_Caption[];
extern char Label12_Caption[];
extern char Label13_Caption[];
extern char Label14_Caption[];
extern char S_condenser_1_Caption[];
extern char S_suction_1_Caption[];
extern char Label15_Caption[];
extern char Label17_Caption[];
extern char Label18_Caption[];
extern char Label28_Caption[];
extern char Label31_Caption[];
extern char Label32_Caption[];
extern char Home_b13_Caption[];
extern char Back_b10_Caption[];
extern char CircleButton10_Caption[];
extern char S_Low_Pressure_1_Caption[];
extern char S_High_Pressure_1_Caption[];
extern char Label70_Caption[];
extern char Label72_Caption[];
extern char Next_b6_Caption[];
extern char Label27_Caption[];
extern char Label35_Caption[];
extern char BrineIN_sign_Caption[];
extern char BrineOUT_sign_Caption[];
extern char Super_sign_Caption[];
extern char Cond_sign_Caption[];
extern char Cool_sign_Caption[];
extern char Image192_Caption[];
extern char Image33_Caption[];
extern char Image34_Caption[];
extern char Image266_Caption[];
extern char Image265_Caption[];
extern char Image264_Caption[];
extern char Image243_Caption[];
extern char Image244_Caption[];
extern char Image245_Caption[];
extern char Image24_Caption[];
extern char Home_b14_Caption[];
extern char Next_b7_Caption[];
extern char Image236_Caption[];
extern char Image237_Caption[];
extern char Image238_Caption[];
extern char Image53_Caption[];
extern char Image86_Caption[];
extern char Image95_Caption[];
extern char Set_max_superheat_Caption[];
extern char Set_min_subcooling_Caption[];
extern char Set_max_subcooling_Caption[];
extern char Set_max_high_pressure_Caption[];
extern char Set_min_lhigh_pressure_Caption[];
extern char Seeting4_label_Caption[];
extern char CircleButton4_Caption[];
extern char Back_b11_Caption[];
extern char Label390_Caption[];
extern char Down_21__Caption[];
extern char Down_20__Caption[];
extern char Down_19__Caption[];
extern char Down_22__Caption[];
extern char Down_23__Caption[];
extern char Up_22__Caption[];
extern char Up_21__Caption[];
extern char Up_20__Caption[];
extern char Up_19__Caption[];
extern char Up_23__Caption[];
extern char Set_22__Caption[];
extern char Set_21__Caption[];
extern char Set_20__Caption[];
extern char Set_19__Caption[];
extern char Set_23__Caption[];
extern const char Image390_Caption[];
extern char Image1_Caption[];
extern char Image4_Caption[];
extern char Image98_Caption[];
extern char Image94_Caption[];
extern char Image68_Caption[];
extern char Image67_Caption[];
extern char Image66_Caption[];
extern char Image65_Caption[];
extern char Image64_Caption[];
extern char Image36_Caption[];
extern char Image35_Caption[];
extern char Image19_Caption[];
extern char Image9_Caption[];
extern char Image8_Caption[];
extern char D_Source_1_Caption[];
extern char D_Heating_1_Caption[];
extern char D_Reverse_1_Caption[];
extern char D_Compr_1_Caption[];
extern char D_DHW_Caption[];
extern char Device_label_Caption[];
extern char D_Electric_Caption[];
extern char D_GAZ_Caption[];
extern char D_Compr_2_Caption[];
extern char D_Source_2_Caption[];
extern char D_Heating_2_Caption[];
extern char D_Reverse_2_Caption[];
extern char D_Solar_Caption[];
extern char D_fan2_Caption[];
extern char D_fan1_Caption[];
extern char Pump1_Caption[];
extern char Pump2_Caption[];
extern char Revers1_Caption[];
extern char Compr_1_Caption[];
extern char Valve_1_Caption[];
extern char Label59_Caption[];
extern char Label62_Caption[];
extern char Label64_Caption[];
extern char Label65_Caption[];
extern char Label67_Caption[];
extern char Label68_Caption[];
extern char Home_b15_Caption[];
extern char Electricobject_TatDiagram_Caption[];
extern char Image37_Caption[];
extern char Box23_Caption[];
extern char Line1_Caption[];
extern char Line2_Caption[];
extern char Line3_Caption[];
extern char Line8_Caption[];
extern char Line9_Caption[];
extern char Line10_Caption[];
extern char Line11_Caption[];
extern char Line12_Caption[];
extern char graph1_pos_Caption[];
extern char Label83_Caption[];
extern char Label84_Caption[];
extern char Label85_Caption[];
extern char Label86_Caption[];
extern char Label87_Caption[];
extern char Label88_Caption[];
extern char Label89_Caption[];
extern char Label90_Caption[];
extern char Label91_Caption[];
extern char Label92_Caption[];
extern char Label93_Caption[];
extern char Line4_Caption[];
extern char Line5_Caption[];
extern char Line6_Caption[];
extern char Label47_Caption[];
extern char Label94_Caption[];
extern char Line7_Caption[];
extern char Image269_Caption[];
extern char GraphTimelabel_Caption[];
extern char Graph_Label_Caption[];
extern char graph_br1_in_Caption[];
extern char graph_br1_out_Caption[];
extern char graph_heat1_in_Caption[];
extern char graph_heat1_out_Caption[];
extern char Home_b16_Caption[];
extern char Next_b8_Caption[];
extern char Back_b12_Caption[];
extern char CircleButton11_Caption[];
extern char Label377_Caption[];
extern char Label378_Caption[];
extern char Label380_Caption[];
extern char Label381_Caption[];
extern char Label382_Caption[];
extern char Image69_Caption[];
extern char Image71_Caption[];
extern char Label42_Caption[];
extern char Image73_Caption[];
extern char Image74_Caption[];
extern char Image75_Caption[];
extern char Image76_Caption[];
extern char Image77_Caption[];
extern char Image79_Caption[];
extern char S_Brine_In_1_Caption[];
extern char S_Brine_Out_1_Caption[];
extern char S_Heat_Out_1_Caption[];
extern char S_Heat_In_1_Caption[];
extern char Sens_DHW_Caption[];
extern char S_tank_Caption[];
extern char S_ComprEx_1_Caption[];
extern char S_High_Press_1_Caption[];
extern char S_Low_Press_1_Caption[];
extern char S_SH_1_Caption[];
extern char Image78_Caption[];
extern char Image80_Caption[];
extern char flow_source_Caption[];
extern char flow_heat_Caption[];
extern char Image117_Caption[];
extern char Image118_Caption[];
extern char Image119_Caption[];
extern char Image120_Caption[];
extern char Image124_Caption[];
extern char Image126_Caption[];
extern char Image127_Caption[];
extern char Image131_Caption[];
extern char flow_sun_Caption[];
extern char draw_One_ground_back_Caption[];
extern char Image41_Caption[];
extern char Power_220V_Caption[];
extern char Label239_Caption[];
extern char Two_Compressors_Caption[];
extern char Reversing_Heat_OFF_Caption[];
extern char Flow_Source_sensor_OFF_Caption[];
extern char Flow_Source_Heat1_OFF_Caption[];
extern char Flow_Source_Heat2_OFF_Caption[];
extern char One_Compressors_Caption[];
extern char Reversing_ON_HEAT_Caption[];
extern char Flow_Source__Sensor_ON_Caption[];
extern char Flow_Source__Heat1_ON_Caption[];
extern char Flow_Source__Heat2_ON_Caption[];
extern char Power_380V_Caption[];
extern char Home_b17_Caption[];
extern char Next_b9_Caption[];
extern char Back_13_Caption[];
extern char CircleButton12_Caption[];
extern char Image43_Caption[];
extern char Image140_Caption[];
extern char Image150_Caption[];
extern char Image136_Caption[];
extern char Image137_Caption[];
extern char Image151_Caption[];
extern char Image191_Caption[];
extern char Image190_Caption[];
extern char Image148_Caption[];
extern char Image149_Caption[];
extern char Image189_Caption[];
extern char Image188_Caption[];
extern char Image143_Caption[];
extern char Label63_Caption[];
extern char Image152_Caption[];
extern char furnance_time_ON_Caption[];
extern char Furnance_start_temp_Down_Caption[];
extern char Furnance_off_down_Caption[];
extern char Furnance_time_down_Caption[];
extern char Furnance_start_temp_UP_Caption[];
extern char Furnance_HP_OFF_UP_Caption[];
extern char Furnance_off_up_Caption[];
extern char Furnance_time_up_Caption[];
extern char Furnance_HP_OFF_Dowm_Caption[];
extern char furnance_time_OFF_Caption[];
extern char furnance_Mode_on_Caption[];
extern char Box14_Caption[];
extern char Box15_Caption[];
extern char Home_b18_Caption[];
extern char Back_b14_Caption[];
extern char Furnance_temperature_ON_Caption[];
extern char heat_pump_OFF_Caption[];
extern char furnance_OFF_Caption[];
extern char furnance_Timer_Caption[];
extern char Furnance_off_save_Caption[];
extern char Furnance_HP_OFF_save_Caption[];
extern char Image107_Caption[];
extern char Box7_Caption[];
extern char Box8_Caption[];
extern char Box9_Caption[];
extern char Box10_Caption[];
extern char IPAddressLabel_Caption[];
extern char MaskLabel_Caption[];
extern char GATELabel_Caption[];
extern char DNSLabel_Caption[];
extern char LANSet_Caption[];
extern char SetGateWay_Caption[];
extern char SetDNS_Caption[];
extern char SetIPAddress_Caption[];
extern char SetMask_Caption[];
extern char LAN_Key_1_Caption[];
extern char LAN_Key_2_Caption[];
extern char LAN_Key_3_Caption[];
extern char LAN_Key_4_Caption[];
extern char LAN_Key_5_Caption[];
extern char LAN_Key_6_Caption[];
extern char LAN_Key_7_Caption[];
extern char LAN_Key_8_Caption[];
extern char LAN_Key_9_Caption[];
extern char LAN_Key_0_Caption[];
extern char Label40_Caption[];
extern char LAN_Key_Dot_Caption[];
extern char LAN_Key_Clear_Caption[];
extern char Home_b19_Caption[];
extern char Back_b15_Caption[];
extern char Image146_Caption[];
extern char Image109_Caption[];
extern char Image147_Caption[];
extern char Image153_Caption[];
extern char Label44_Caption[];
extern char Image114_Caption[];
extern char Image115_Caption[];
extern char Image116_Caption[];
extern char Image121_Caption[];
extern char Image122_Caption[];
extern char Image123_Caption[];
extern char Image128_Caption[];
extern char Image129_Caption[];
extern char Image130_Caption[];
extern char Image135_Caption[];
extern char Image138_Caption[];
extern char Set_DHW_HY_Caption[];
extern char Hyst_Heat_down_Caption[];
extern char Hyst_DHW_down_Caption[];
extern char Hyst_Heat_up_Caption[];
extern char Hyst_Cool_up_Caption[];
extern char Hyst_DHW_up_Caption[];
extern char Hyst_Cool_down_Caption[];
extern char Home_b20_Caption[];
extern char Back_b16_Caption[];
extern char Hysteresis_heating_Caption[];
extern char Hysteresis_cooling_Caption[];
extern char Hysteresis_DHW_Caption[];
extern char Image62_Caption[];
extern char Label69_Caption[];
extern char Image134_Caption[];
extern char HP2_gauge_Caption[];
extern char LP2_gauge_Caption[];
extern char HP2_arrow_Caption[];
extern char LP2_arrow_Caption[];
extern char Home_b22_Caption[];
extern char Back_b18_Caption[];
extern char CircleButton15_Caption[];
extern char Image142_Caption[];
extern char Module2_br_outlet_Caption[];
extern char Label81_Caption[];
extern char Module2_heat_inlet_Caption[];
extern char Module2_heat_outlet_Caption[];
extern char Module2_compressor_Caption[];
extern char Module2_SH_Caption[];
extern char Module2_SC_Caption[];
extern char S_Brine_Inlet_2_Caption[];
extern char S_Brine_Outlet_2_Caption[];
extern char S_Heat_Inlet_2_Caption[];
extern char S_Heat_Outlet_2_Caption[];
extern char S_Compressor_2_Caption[];
extern char S_Superheat_2_Caption[];
extern char S_Subcool_2_Caption[];
extern char Label100_Caption[];
extern char Label101_Caption[];
extern char Label102_Caption[];
extern char Label103_Caption[];
extern char Label105_Caption[];
extern char Label106_Caption[];
extern char Label107_Caption[];
extern char Label108_Caption[];
extern char Label109_Caption[];
extern char Label110_Caption[];
extern char Label111_Caption[];
extern char Label112_Caption[];
extern char Label113_Caption[];
extern char Label114_Caption[];
extern char Label115_Caption[];
extern char Label116_Caption[];
extern char Module2_br_flow_Caption[];
extern char S_Source_Flow_2_Caption[];
extern char Module2_heat_flow_Caption[];
extern char S_Heat_Flow_2_Caption[];
extern char Label119_Caption[];
extern char Label120_Caption[];
extern char Label128_Caption[];
extern char Label129_Caption[];
extern char Label76_Caption[];
extern char S_condenser_2_Caption[];
extern char S_suction_2_Caption[];
extern char Module2_cond_Caption[];
extern char Module2_suct_Caption[];
extern char ButtonRound14_Caption[];
extern char Home_b23_Caption[];
extern char CircleButton16_Caption[];
extern char S_Low_Pressure_2_Caption[];
extern char S_High_Pressure_2_Caption[];
extern char Label283_Caption[];
extern char Label284_Caption[];
extern char Label3_Caption[];
extern char Label26_Caption[];
extern char Image157_Caption[];
extern char Label80_Caption[];
extern char Mode_air_on_Caption[];
extern char Mode_ground_on_Caption[];
extern char Home_b24_Caption[];
extern char Back_20_Caption[];
extern char CircleButton13_Caption[];
extern char Image159_Caption[];
extern char Image273_Caption[];
extern char Image162_Caption[];
extern char Image176_Caption[];
extern char Image174_Caption[];
extern char Image166_Caption[];
extern char Image276_Caption[];
extern char Image175_Caption[];
extern char Image274_Caption[];
extern char Image267_Caption[];
extern char Image164_Caption[];
extern char Image270_Caption[];
extern char Image165_Caption[];
extern char Label82_Caption[];
extern char Image203_Caption[];
extern char Module1_br_inlet_Caption[];
extern char Module1_br_outlet_Caption[];
extern char Module1_heat_outlet_Caption[];
extern char Module1_heat_inlet_Caption[];
extern char TANK_Caption[];
extern char DHW_Caption[];
extern char Module1_exhaust_Caption[];
extern char Module1_superheat_Caption[];
extern char Module1_heat_flow_Caption[];
extern char Image181_Caption[];
extern char Image160_Caption[];
extern char Button7_Caption[];
extern char Button9_Caption[];
extern char Button10_Caption[];
extern char Button11_Caption[];
extern char Module2_exhaust_Caption[];
extern char Module2_superheat_Caption[];
extern char Module2_brine_flow_Caption[];
extern char Button15_Caption[];
extern char Image178_Caption[];
extern char Image183_Caption[];
extern char Image271_Caption[];
extern char Image272_Caption[];
extern char Image172_Caption[];
extern char Image182_Caption[];
extern char Image204_Caption[];
extern char Image180_Caption[];
extern char Image275_Caption[];
extern char Image202_Caption[];
extern char Label95_Caption[];
extern char Button13_Caption[];
extern char Button5_Caption[];
extern char Image278_Caption[];
extern char Label96_Caption[];
extern char Time2_reverse_Caption[];
extern char Time2_ground_pump_Caption[];
extern char Time2_heat_pump_Caption[];
extern char Time2_compressor_Caption[];
extern char Home_b25_Caption[];
extern char Time_solar_Caption[];
extern char CircleButton7_Caption[];
extern char Back_b21_Caption[];
extern char Label9_Caption[];
extern char Image289_Caption[];
extern char Image324_Caption[];
extern char Image290_Caption[];
extern char Image297_Caption[];
extern char Image296_Caption[];
extern char Image326_Caption[];
extern char Image327_Caption[];
extern char Image330_Caption[];
extern char Image329_Caption[];
extern char Image325_Caption[];
extern char Image291_Caption[];
extern char Label97_Caption[];
extern char Image303_Caption[];
extern char Label98_Caption[];
extern char Image301_Caption[];
extern char Image318_Caption[];
extern char Image320_Caption[];
extern char Image328_Caption[];
extern char Image331_Caption[];
extern char Image322_Caption[];
extern char Image321_Caption[];
extern char Image332_Caption[];
extern char Image323_Caption[];
extern char Image292_Caption[];
extern char Image293_Caption[];
extern char Image305_Caption[];
extern char Image319_Caption[];
extern char Button17_Caption[];
extern char Button18_Caption[];
extern char Button19_Caption[];
extern char Button20_Caption[];
extern char Button22_Caption[];
extern char Button23_Caption[];
extern char Button25_Caption[];
extern char Button28_Caption[];
extern char Button29_Caption[];
extern char Button30_Caption[];
extern char Button31_Caption[];
extern char Button33_Caption[];
extern char Button34_Caption[];
extern char Button16_Caption[];
extern char Image299_Caption[];
extern char Button6_Caption[];
extern char Image333_Caption[];
extern char Image336_Caption[];
extern char Image339_Caption[];
extern char Image338_Caption[];
extern char Image343_Caption[];
extern char Image342_Caption[];
extern char Image341_Caption[];
extern char Image352_Caption[];
extern char Image334_Caption[];
extern char Label99_Caption[];
extern char Image358_Caption[];
extern char Image360_Caption[];
extern char Image362_Caption[];
extern char Image365_Caption[];
extern char Image367_Caption[];
extern char Image368_Caption[];
extern char Image361_Caption[];
extern char Image340_Caption[];
extern char Image337_Caption[];
extern char Button14_Caption[];
extern char Button26_Caption[];
extern char Button27_Caption[];
extern char Button32_Caption[];
extern char Button35_Caption[];
extern char Button36_Caption[];
extern char Button37_Caption[];
extern char Button38_Caption[];
extern char Button39_Caption[];
extern char Button41_Caption[];
extern char Button42_Caption[];
extern char Button2_Caption[];
extern char Image374_Caption[];
extern char Box28_Caption[];
extern char Line13_Caption[];
extern char Line14_Caption[];
extern char Line15_Caption[];
extern char Line17_Caption[];
extern char Line18_Caption[];
extern char Line19_Caption[];
extern char Line20_Caption[];
extern char Line21_Caption[];
extern char Label121_Caption[];
extern char Label122_Caption[];
extern char Label125_Caption[];
extern char Label127_Caption[];
extern char Label130_Caption[];
extern char Label131_Caption[];
extern char Label132_Caption[];
extern char Label133_Caption[];
extern char Label134_Caption[];
extern char Label135_Caption[];
extern char Label136_Caption[];
extern char Line22_Caption[];
extern char Line23_Caption[];
extern char Line24_Caption[];
extern char Label137_Caption[];
extern char Label146_Caption[];
extern char Line25_Caption[];
extern char Image378_Caption[];
extern char Label151_Caption[];
extern char __Caption[];
extern char Home_b26_Caption[];
extern char Back_b22_Caption[];
extern char graph2_pos_Caption[];
extern char graph_br2_in_Caption[];
extern char graph_br2_out_Caption[];
extern char graph_heat2_in_Caption[];
extern char graph_heat2_out_Caption[];
extern char Label5_Caption[];
extern char Label8_Caption[];
extern char Label16_Caption[];
extern char Label19_Caption[];
extern char Label21_Caption[];
extern char CircleButton5_Caption[];
extern char Image133_Caption[];
extern char Image395_Caption[];
extern char Image393_Caption[];
extern char Image161_Caption[];
extern char Image295_Caption[];
extern char Image376_Caption[];
extern char Image391_Caption[];
extern char Image111_Caption[];
extern char Image402_Caption[];
extern char Image403_Caption[];
extern char Image405_Caption[];
extern char Image404_Caption[];
extern char Image406_Caption[];
extern char Image113_Caption[];
extern char Label162_Caption[];
extern char Home_b27_Caption[];
extern char Back_b23_Caption[];
extern char Image108_Caption[];
extern char Label126_Caption[];
extern char Home_b28_Caption[];
extern char Back_b24_Caption[];
extern char Energy_Volt_1_Caption[];
extern char Label251_Caption[];
extern char Label252_Caption[];
extern char S_Current_1_Caption[];
extern char Label253_Caption[];
extern char Energy_Volt_2_Caption[];
extern char Label254_Caption[];
extern char Label255_Caption[];
extern char S_Current_2_Caption[];
extern char Label256_Caption[];
extern char Energy_Volt_3_Caption[];
extern char Label257_Caption[];
extern char Label258_Caption[];
extern char S_Current_3_Caption[];
extern char Label259_Caption[];
extern char Energy_Power_1_Caption[];
extern char Label260_Caption[];
extern char Label261_Caption[];
extern char ButtonRound12_Caption[];
extern char Label400_Caption[];
extern char Label401_Caption[];
extern char Image82_Caption[];
extern char Image388_Caption[];
extern char Defrost_set4_Caption[];
extern char Image355_Caption[];
extern char Image198_Caption[];
extern char Image199_Caption[];
extern char Defrost_on_time_Caption[];
extern char Image377_Caption[];
extern char Image379_Caption[];
extern char Image382_Caption[];
extern char Image383_Caption[];
extern char Image381_Caption[];
extern char Image384_Caption[];
extern char Defrost_off_time_Caption[];
extern char Defrost_on_temperature_Caption[];
extern char Defrost_off_temperature_Caption[];
extern char Home_b29_Caption[];
extern char Back_b25_Caption[];
extern char Defrost_minus1_Caption[];
extern char Defrost_minus2_Caption[];
extern char Defrost_minus3_Caption[];
extern char Defrost_plus1_Caption[];
extern char Defrost_plus2_Caption[];
extern char Defrost_plus3_Caption[];
extern char Defrost_set1_Caption[];
extern char Defrost_set2_Caption[];
extern char Defrost_set3_Caption[];
extern char Image386_Caption[];
extern char Image387_Caption[];
extern char Defrost_plus4_Caption[];
extern char Defrost_minus4_Caption[];
extern char Defrost_on_humidity_Caption[];
extern char Image47_Caption[];
extern char Image70_Caption[];
extern char Image103_Caption[];
extern char Label51_Caption[];
extern char humidity_down_Caption[];
extern char humidity_up_Caption[];
extern char humidity_set_Caption[];
extern char ButtonRound2_Caption[];
extern char Image63_Caption[];
extern char Home_b30_Caption[];
extern char BoxRound1_Caption[];
extern char Back_b26_Caption[];
extern char Label50_Caption[];
extern char Image21_Caption[];
extern char Image22_Caption[];
extern char Image29_Caption[];
extern char Image280_Caption[];
extern char Image99_Caption[];
extern char Image100_Caption[];
extern char Image281_Caption[];
extern char Home_b31_Caption[];
extern char Set_max_low_pressure_Caption[];
extern char Set_min_low_pressure_Caption[];
extern char Image12_Caption[];
extern char Image14_Caption[];
extern char Image17_Caption[];
extern char Image18_Caption[];
extern char Image282_Caption[];
extern char Image279_Caption[];
extern char Back_b27_Caption[];
extern char Label46_Caption[];
extern char CircleButton3_Caption[];
extern char Set_phase_off_Caption[];
extern char Set_voltage_off_Caption[];
extern char Set_voltage_on_Caption[];
extern char Set_phase_on_Caption[];
extern char Image5_Caption[];
extern char Image6_Caption[];
extern char Image46_Caption[];
extern char UP_26__Caption[];
extern char Set_26__Caption[];
extern char Set_eev_on_Caption[];
extern char Image7_Caption[];
extern char Image2_Caption[];
extern char Back_b28_Caption[];
extern char Home_b32_Caption[];
extern char Label7_Caption[];
extern char Image461_Caption[];
extern char Image469_Caption[];
extern char Image471_Caption[];
extern char Image472_Caption[];
extern char Image473_Caption[];
extern char Image470_Caption[];
extern char Image468_Caption[];
extern char Image482_Caption[];
extern char Image474_Caption[];
extern char Image478_Caption[];
extern char Image479_Caption[];
extern char Image475_Caption[];
extern char Image483_Caption[];
extern char Image484_Caption[];
extern char Image476_Caption[];
extern char Image480_Caption[];
extern char Image481_Caption[];
extern char Image477_Caption[];
extern char Image485_Caption[];
extern char Home_b33_Caption[];
extern char Back_b29_Caption[];
extern char Next_b10_Caption[];
extern char Down_15__Caption[];
extern char Down_16__Caption[];
extern char Down_17__Caption[];
extern char Down_18__Caption[];
extern char Up_15__Caption[];
extern char Up_16__Caption[];
extern char Up_17__Caption[];
extern char Up_18__Caption[];
extern char Set_15__Caption[];
extern char Set_16__Caption[];
extern char Set_17__Caption[];
extern char Set_18__Caption[];
extern char Set_14__Caption[];
extern char Set_13__Caption[];
extern char Up_14__Caption[];
extern char Up_13__Caption[];
extern char Down_14__Caption[];
extern char Down_13__Caption[];
extern char Set_Furnance_one_preset_Caption[];
extern char Set_solar_max_Caption[];
extern char Set_max_electric_Caption[];
extern char Set_max_furnance_Caption[];
extern char Set_electric_preset_Caption[];
extern char Set_min_superheat_Caption[];
extern char Label341_Caption[];
extern char CircleButton17_Caption[];


void DrawScreen(TScreen *aScreen);
void DrawButton(TButton *aButton);
void DrawRoundButton(TButton_Round *Around_button);
void DrawLabel(TLabel *ALabel);
void DrawImage(TImage *AImage);
void DrawCImage(TCImage *ACimage);
void DrawCircle(TCircle *ACircle);
void DrawCircleButton(TCircleButton *ACircle_button);
void DrawBox(TBox *ABox);
void DrawRoundBox(TBox_Round *Around_box);
void DrawLine(TLine *Aline);
void DrawProgressBar(TProgressBar *AProgressBar);
void UpdatePBPosition(TProgressBar *AProgressBar);
void Check_TP();
void Start_TP();
void Process_TP_Press(unsigned int X, unsigned int Y);
void Process_TP_Up(unsigned int X, unsigned int Y);
void Process_TP_Down(unsigned int X, unsigned int Y);
#line 1 "c:/users/dumitru/desktop/dima/alta_2_compressor_display/controller_code/mikroc pro for arm/controller_resources.h"
#line 1 "c:/mikroc/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/mikroc/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 7 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
unsigned char tenYearU;
unsigned char oneYearU;
unsigned char oneMonth;
unsigned char tenDayU;
unsigned char oneDayU;
unsigned char tenHour;
unsigned char oneHour;
unsigned char tenMinute;
unsigned char oneMinute;
unsigned char countPacket;
float press;
extern RTC_TimeTypeDef My_Time;
extern RTC_TimeTypeDef Read_Time;
extern RTC_DateTypeDef My_Date;
extern RTC_DateTypeDef Read_Date;

extern float old_HP_pressure;
extern float old_LP_pressure;

extern  _Bool  pushButton;
extern  _Bool  msgOk;
extern void (*send_data_again)();

regAdress adressReg;
unsigned char nomReg;

extern TScreen* CurrentScreen;
TScreen BackScreen,NextScreen;
extern Packet bus_data;
extern int system_reg[600];
 _Bool  two_compressors_mode,ground_heat_pump,SYSTEM_ON;
extern  _Bool  sendMessage;
unsigned char num_page;
int incTRV=0;

 RTC_TimeTypeDef My_Time;
 RTC_DateTypeDef My_Date;

void Tone1() {
 Sound_Play(659, 35);
}
void Tone2() {
 Sound_Play(698, 50);
}
void Tone3() {
 Sound_Play(784, 70);
}
void BLED_Fade_Out(){
 unsigned char i;

 for ( i = 255; i > 0 ; i-- ){
 TFT_Set_DBC_SSD1963(i);
 Delay_us(500);
 }
 TFT_Set_DBC_SSD1963(0);
}
void BLED_Fade_In(){
 unsigned char i;

 for (i = 1; i < 255; i++){
 TFT_Set_DBC_SSD1963(i);
 Delay_us(500);
 }
 TFT_Set_DBC_SSD1963(255);
}



void BackToHome(){
 Tone2();
 BLED_Fade_Out();
 DrawScreen(&HOME);
 BLED_Fade_In();
}
void goToBack(){
 Tone2();


if( num_page==0)
 {
 if(CurrentScreen == &SYSTEM_SET) {BLED_Fade_Out();DrawScreen(&USER_MENU);BLED_Fade_In(); }
 else if (CurrentScreen==&ERRORS) {BLED_Fade_Out();DrawScreen(&USER_MENU);BLED_Fade_In();}
 else if (CurrentScreen==&SENSOR1) {BLED_Fade_Out();DrawScreen(&USER_MENU);BLED_Fade_In();}
 else if (CurrentScreen==&SETTINGS) {BLED_Fade_Out();DrawScreen(&USER_MENU);BLED_Fade_In();}
 else if (CurrentScreen==&ENERGY) {BLED_Fade_Out();DrawScreen(&USER_MENU);BLED_Fade_In();}
 else if (CurrentScreen==&DEFROST) {BLED_Fade_Out();DrawScreen(&USER_MENU);BLED_Fade_In();}
 else if(CurrentScreen == &EEV) {BLED_Fade_Out();DrawScreen(&SYSTEM_SET);BLED_Fade_In();}
 else if(CurrentScreen == &MODE) {BLED_Fade_Out();DrawScreen(&SYSTEM_SET);BLED_Fade_In();}
 else if(CurrentScreen == &DELAY_MENU) {BLED_Fade_Out();DrawScreen(&SYSTEM_SET);BLED_Fade_In(); }
 else if(CurrentScreen == &LIMITS1) {BLED_Fade_Out();DrawScreen(&SYSTEM_SET);BLED_Fade_In();}
 else if(CurrentScreen == &SYSTEM_EVENTS) {BLED_Fade_Out();DrawScreen(&SYSTEM_SET);BLED_Fade_In(); }
 else if (CurrentScreen==&LIMITS2) {BLED_Fade_Out();DrawScreen(&LIMITS1);BLED_Fade_In(); }
 else if (CurrentScreen==&LIMITS3) {BLED_Fade_Out();DrawScreen(&LIMITS2);BLED_Fade_In(); }
 else if (CurrentScreen==&LIMITS4) {BLED_Fade_Out();DrawScreen(&LIMITS3);BLED_Fade_In();}
 else if (CurrentScreen==&LIMITS5) {BLED_Fade_Out();DrawScreen(&LIMITS4);BLED_Fade_In(); }
 else if (CurrentScreen==&MODE2) {BLED_Fade_Out();DrawScreen(&MODE);BLED_Fade_In(); }
 }
 else num_page=0;


}
void nextPage()
{
 Tone2();

 if( num_page==0 && two_compressors_mode) num_page=1;
 if (CurrentScreen==&LIMITS1){BLED_Fade_Out();DrawScreen(&LIMITS2);BLED_Fade_In();}
 else if (CurrentScreen==&LIMITS2){BLED_Fade_Out();DrawScreen(&LIMITS3);BLED_Fade_In();}
 else if (CurrentScreen==&LIMITS3){BLED_Fade_Out();DrawScreen(&LIMITS4);BLED_Fade_In();}
 else if (CurrentScreen==&LIMITS4){BLED_Fade_Out();DrawScreen(&LIMITS5);BLED_Fade_In();}
 else if (CurrentScreen==&MODE){BLED_Fade_Out();DrawScreen(&MODE2);BLED_Fade_In();}

}
void selectPage(){
 static int lastDataDhw;
 static TScreen* lastScreen=0;
 int convert_temp;
 char txt[15];
 if (lastScreen!=CurrentScreen) {countPacket=1; lastScreen=CurrentScreen; }
if (CurrentScreen==&HOME)
 {

 main_page();
 switch(countPacket)
 {
 case 1:reciev_data_packet(BAC_TEMP,5); break;





 case 2:countPacket=1;break;
 }
 }

else if(CurrentScreen==&SENSOR1)
 {
 sensor_1(num_page);

 if(num_page==0)
 {
 switch(countPacket)
 {
 case 1: reciev_data_packet(BAC_TEMP,14);break;

 case 2: countPacket=1;break;
 }
 if(strcmp(CircleButton10.Caption,"1")!=0){CircleButton10.Caption="1";DrawCircleButton(&CircleButton10); }
 }
 else
 {
 switch(countPacket)
 {
 case 1: reciev_data_packet(BAC_TEMP,2);break;
 case 2: reciev_data_packet(SOURC_IN_2,11);break;
 case 3: countPacket=1;break;
 }
 if(strcmp(CircleButton10.Caption,"2")!=0) {CircleButton10.Caption="2";DrawCircleButton(&CircleButton10);Back_b10.OnClickPtr=goToBack;}
 }
 }


else if(CurrentScreen==&GAUGE1)
{
 if(num_page==0)
 {
 LP_display(system_reg[LOW_PRESS_1]),HP_display(system_reg[HIGH_PRESS_1]);reciev_data_packet(HIGH_PRESS_1,2);
 if(strcmp(CircleButton8.Caption,"1")!=0) {CircleButton8.Caption="1";DrawCircleButton(&CircleButton8);Next_b2.Caption="NEXT";DrawRoundButton(&Next_b2);Next_b2.OnClickPtr=nextPage;}
 }
 else
 {
 LP_display(system_reg[LOW_PRESS_2]),HP_display(system_reg[HIGH_PRESS_2]);reciev_data_packet(HIGH_PRESS_2,2);
 if(strcmp(CircleButton8.Caption,"2")!=0){CircleButton8.Caption="2";DrawCircleButton(&CircleButton8);Next_b2.Caption="BACK";DrawRoundButton(&Next_b2);Next_b2.OnClickPtr=goToBack;}
 }
}
else if(CurrentScreen==&EEV)
 {
 count_steps(num_page);
 if(num_page==0)
 {
 switch(countPacket)
 {
 case 1:reciev_data_packet(TRV_STEPS_1,1); break;
 case 2:reciev_data_packet(S_HEAT_1,1); break;
 case 3:reciev_data_packet(TRV_CORRECT_1,1); break;
 case 4: countPacket=1;break;
 }
 if(strcmp(CircleButton9.Caption,"1")!=0) {CircleButton9.Caption="1";DrawCircleButton(&CircleButton9);}
 }
 else
 {
 switch(countPacket)
 {
 case 1:reciev_data_packet(TRV_STEPS_2,1); break;
 case 2:reciev_data_packet(S_HEAT_2,1); break;
 case 3:reciev_data_packet(TRV_CORRECT_2,1); break;
 case 4: countPacket=1;break;
 }
 if(strcmp(CircleButton9.Caption,"2")!=0) {CircleButton9.Caption="2";DrawCircleButton(&CircleButton9);Back_b2.OnClickPtr=goToBack;}
 }
 }

else if(CurrentScreen==&SYSTEM_EVENTS)
{
 working_time(num_page);
 if(num_page==0) {
 reciev_data_packet(TIM_COM_1,4);
 if(strcmp(CircleButton6.Caption,"1")!=0) {CircleButton6.Caption="1";DrawCircleButton(&CircleButton6);}
 }
 else {
 reciev_data_packet(TIM_COM_2,4);
 if(strcmp(CircleButton6.Caption,"2")!=0) {CircleButton6.Caption="2";DrawCircleButton(&CircleButton6);Back_b7.OnClickPtr=goToBack;}
 }

}
else if(CurrentScreen==&Schema1)
 {
 schema1_page();
 switch(countPacket)
 {
 case 1:reciev_data_packet(BAC_TEMP,2); break;
 case 2:reciev_data_packet(CONDENS_TEMP_1,11); break;
 case 3:reciev_data_packet(COM_STATE_1,5); break;
 case 4: countPacket=1;break;
 }
 }
else if (CurrentScreen==&Schema2)
 {
 switch(countPacket)
 {
 case 1:reciev_data_packet(BAC_TEMP,2); break;
 case 2:reciev_data_packet(CONDENS_TEMP_2,11); break;
 case 3:reciev_data_packet(COM_STATE_2,5); break;
 case 4: countPacket=1;break;
 }

 }

}


void Main_OFFOnClick()
{
 if ((unsigned long)Main_OFF.Picture_Name ==  0x00084B44 )
 {
 Main_OFF.Picture_Name =  0x000827A2 ;
 DrawImage(&Main_ON);



 SYSTEM_ON= 1 ;
 system_reg[POWER]=1;

 }
 else {
 Main_OFF.Picture_Name =  0x00084B44 ;
 DrawImage(&Main_OFF);



 SYSTEM_ON= 0 ;
 system_reg[POWER]=0;
 }

 send_data_packet(POWER,2);

}
void bar_heatingOnClick()
{

 if ( strcmp(bar_heating.Caption,"HEATING")==0 )
 {
 bar_heating.Caption = "COOLING";
 DrawRoundButton(&bar_heating);
 DrawImage(&cool_icon);

 system_reg[COOL]=1;
 system_reg[HEAT]=0;

 }
 else if(strcmp(bar_heating.Caption,"COOLING")==0)
 {
 bar_heating.Caption = "HEATING";
 DrawRoundButton(&bar_heating);
 DrawImage(&heat_icon);

 system_reg[HEAT]=1;
 system_reg[COOL]=0;
 }

 if (strcmp(ON_OFF_Heat_Cool.Caption,"ON")==0 ) {
 send_data_packet(COOL,2);

 }

}
void DHW_SetingOnClick()
{ static unsigned char count_push = 0;
 char txt[7];
 if(count_push==0) {
 Set_Dhw_Box.Visible = 1;
 Set_Dhw_Box.Active = 1;
 DHW_UP.Visible = 1;
 DHW_UP.Active = 1;
 DHW_DOWN.Visible = 1;
 DHW_DOWN.Active = 1;
 DHW_Setting_value.Visible = 1;
 DHW_Setting_value.Active = 1;
 dhw_T.Visible = 0;
 dhw_T.Active = 0;
 dhw_point.Active = 0;
 dhw_point.Visible = 0;
 dhw_celc.Visible = 0;
 dhw_celc.Active = 0;
 dhw_led.Visible = 0;
 dhw_led.Active = 0;
 dhw_dec.Visible = 0;
 dhw_dec.Active = 0;
 IntToStr(system_reg[SET_DHW], txt);

 Ltrim(txt);
 strncpy(DHW_Setting_value.Caption, txt, 2);
 if(system_reg[SET_DHW]<10 && system_reg[SET_DHW]>=0){DHW_Setting_value.Caption[1]=DHW_Setting_value.Caption[0];DHW_Setting_value.Caption[0]='0';}
 DHW_Seting.Caption = "SELECT";
 DrawRoundBox(&DWN_Windows);
 DrawRoundButton(&DHW_Seting);

 DrawRoundButton(&DHW_UP);
 DrawRoundButton(&DHW_DOWN);
 DrawLabel (&DHW_Setting_value);
 count_push++;
 }
 else {
 Set_Dhw_Box.Visible = 0;
 Set_Dhw_Box.Active = 0;
 DHW_UP.Visible = 0;
 DHW_UP.Active = 0;
 DHW_DOWN.Visible = 0;
 DHW_DOWN.Active = 0;
 DHW_Setting_value.Visible = 0;
 DHW_Setting_value.Active = 0;
 dhw_T.Visible = 1;
 dhw_T.Active = 1;
 dhw_point.Active = 1;
 dhw_point.Visible = 1;
 dhw_celc.Visible = 1;
 dhw_celc.Active = 1;
 dhw_led.Visible = 1;
 dhw_led.Active = 1;
 dhw_dec.Visible = 1;
 dhw_dec.Active = 1;
 DHW_Seting.Caption = "SET";

 count_push=0;
 DrawRoundBox(&DWN_Windows);
 DrawRoundButton(&DHW_Seting);
 DrawRoundButton (& ON_OFF_DHW);
 DrawImage(&dhw_icon);
 DrawRoundButton(&bar_DHW);
 DrawRoundButton(&dhw_T);
 DrawRoundButton(&dhw_dec);

 DrawCircle(&dhw_led);
 DrawLabel(&dhw_point);
 DrawLabel(&dhw_celc);
 send_data_packet(SET_DHW,1);



 }


}
void Heat_SettingOnClick(){
 static unsigned char count_push = 0;
 char txt[7];

 if(count_push==0) {
 Set_Heat_Box.Visible = 1;
 Set_Heat_Box.Active = 1;
 HEAT_UP.Visible = 1;
 HEAT_UP.Active = 1;
 HEAT_Down.Visible = 1;
 HEAT_Down.Active = 1;
 TEMP_Setting_value.Visible = 1;
 TEMP_Setting_value.Active = 1;
 heat_T.Visible = 0;
 heat_T.Active = 0;
 heat_point.Active = 0;
 heat_point.Visible = 0;
 heat_celc.Visible = 0;
 heat_celc.Active = 0;
 heat_led.Visible = 0;
 heat_led.Active = 0;
 heat_dec.Active = 0;
 heat_dec.Visible = 0;
 if(strcmp(bar_heating.Caption,"HEATING")==0 )IntToStr(system_reg[SET_HEAT], txt);
 else if(strcmp(bar_heating.Caption,"COOLING")==0) IntToStr(system_reg[SET_COOL], txt);
 Ltrim(txt);
 strncpy(TEMP_Setting_value.Caption, txt, 2);
 if(system_reg[SET_HEAT]<10 && system_reg[SET_HEAT]>=0){TEMP_Setting_value.Caption[1]=TEMP_Setting_value.Caption[0];TEMP_Setting_value.Caption[0]='0';}
 Heat_Setting.Caption = "SELECT";
 DrawRoundBox(&Heat_Windows);
 DrawRoundButton(&Heat_Setting);
 DrawRoundButton(&HEAT_UP);
 DrawRoundButton(&HEAT_DOWN);
 DrawLabel (&TEMP_Setting_value);
 count_push++;
 }
 else {
 Set_Heat_Box.Visible = 0;
 Set_Heat_Box.Active = 0;
 HEAT_UP.Visible = 0;
 HEAT_UP.Active = 0;
 HEAT_Down.Visible = 0;
 HEAT_Down.Active = 0;
 TEMP_Setting_value.Visible = 0;
 TEMP_Setting_value.Active = 0;
 heat_T.Visible = 1;
 heat_T.Active = 1;
 heat_point.Active = 1;
 heat_point.Visible = 1;
 heat_celc.Visible = 1;
 heat_celc.Active = 1;
 heat_led.Visible = 1;
 heat_led.Active = 1;
 heat_dec.Active = 1;
 heat_dec.Visible = 1;
 Heat_Setting.Caption = "SET";
 count_push=0;
 DrawRoundBox(&Heat_Windows);
 DrawRoundButton(&Heat_Setting);
 DrawRoundButton (& ON_OFF_Heat_Cool);
 DrawRoundButton(&bar_heating);
 DrawRoundButton(&heat_T);
 DrawRoundButton(&heat_dec);

 DrawCircle(&heat_led);
 DrawLabel(&heat_point);
 DrawLabel(&heat_celc);
 if ( strcmp(bar_heating.Caption,"HEATING")==0 ){ DrawImage(&heat_icon);send_data_packet(SET_HEAT,1); }
 else {DrawImage(&cool_icon);send_data_packet(SET_COOL,1); }
 }



}

void Click_HEAT()
{
 if (strcmp(ON_OFF_Heat_Cool.Caption,"ON")==0 )
 {
 ON_OFF_Heat_Cool.Caption = "OFF";
 DrawRoundButton(&ON_OFF_Heat_Cool);
 system_reg[HEAT]=0;
 system_reg[COOL]=0;
 UART2_Write_Text("OFF");
 }
 else
 { if(strcmp(bar_heating.Caption,"HEATING")==0 ){system_reg[HEAT]=1;system_reg[COOL]=0;}
 else if(strcmp(bar_heating.Caption,"COOLING")==0 ){system_reg[HEAT]=0;system_reg[COOL]=1;}
 ON_OFF_Heat_Cool.Caption = "ON";
 DrawRoundButton(&ON_OFF_Heat_Cool);

 }

 send_data_packet(COOL,2);

}
void Click_DHW()
{

 if (strcmp(ON_OFF_DHW.Caption,"ON")==0)
 {
 ON_OFF_DHW.Caption = "OFF";
 DrawRoundButton(&ON_OFF_DHW);
 system_reg[HEATWATER]=0;
 }
 else
 {
 ON_OFF_DHW.Caption = "ON";
 DrawRoundButton(&ON_OFF_DHW);
 system_reg[HEATWATER]=1;
 }

 send_data_packet(HEATWATER,1);
}
void MainBut1OnUp(){
 Tone2();
 BLED_Fade_Out();
 Image25.Visible = 0;
 DrawScreen(&USER_MENU);
 BLED_Fade_In();

}
void MainBut1OnPress(){
 Image25.Visible = 1;
 DrawImage(&Image25);
}
 void MainBut2OnUp(){
 Tone2();
 BLED_Fade_Out();
 Image40.Visible = 0;
 if (two_compressors_mode== 1  && ground_heat_pump ==  1 ) {
 DrawScreen (&Schema2);
 }
 else if (two_compressors_mode== 1  && ground_heat_pump ==  0 ) {
 DrawScreen (&AIR_TWO);
 }
 else if (two_compressors_mode== 0  && ground_heat_pump ==  0 ) {
 DrawScreen(&Schema1);
 }
 else {
 DrawScreen(&Schema1);
 }

 BLED_Fade_In();

 }
 void MainBut2OnPress(){
 Image40.Visible = 1;
 DrawImage(&Image40);

 }
 void MainBut3OnUp(){
 Tone2();
 BLED_Fade_Out();
 Image44.Visible = 0;
 DrawScreen(&DEVICES);
 BLED_Fade_In();

 }
void MainBut3OnPress(){
 Image44.Visible = 1;
 DrawImage(&Image44);
}
void MainBut4OnUp(){
 Tone2();
 BLED_Fade_Out();
 Image61.Visible = 0;
 old_HP_pressure=0;
 old_LP_pressure=0;
 DrawScreen(&GAUGE1);
 BLED_Fade_In();
}
void MainBut4OnPress(){
 Image61.Visible = 1;
 DrawImage(&Image61);
}
void MainBut5OnUp(){
 Tone2();
 BLED_Fade_Out();
 Image87.Visible = 0;
 DrawScreen(&Graph);
 BLED_Fade_In();
}
void MainBut5OnPress(){
 Image87.Visible = 1;
 DrawImage(&Image87);
}
void DHW_UPOnClick(){
 char txt[7];
 Tone2 ();
 system_reg[SET_DHW]++;
 if(system_reg[SET_DHW]>system_reg[HEAT_MAX]) system_reg[SET_DHW]=system_reg[HEAT_MAX];
 IntToStr(system_reg[SET_DHW], txt);
 Ltrim (txt);
 strncpy(DHW_Setting_value.Caption, txt, 2);
 if(system_reg[SET_DHW]<10 && system_reg[SET_DHW]>=0){DHW_Setting_value.Caption[1]=DHW_Setting_value.Caption[0];DHW_Setting_value.Caption[0]='0';}
 DrawBox(&Set_Dhw_Box);
 DrawLabel (&DHW_Setting_value);
 Delay_ms (100);
}
void DHW_DOWNOnClick(){
 char txt[7];
 Tone2 ();
 system_reg[SET_DHW]--;
 if(system_reg[SET_DHW]<system_reg[HEAT_MIN]) system_reg[SET_DHW]=system_reg[HEAT_MIN];
 IntToStr(system_reg[SET_DHW], txt);
 Ltrim (txt);
 strncpy(DHW_Setting_value.Caption, txt, 2);
 if(system_reg[SET_DHW]<10 && system_reg[SET_DHW]>=0){DHW_Setting_value.Caption[1]=DHW_Setting_value.Caption[0];DHW_Setting_value.Caption[0]='0';}
 DrawBox(&Set_Dhw_Box);
 DrawLabel (&DHW_Setting_value);
 Delay_ms (100);

}
void HEAT_UPOnClick(){
 char txt[7];
 int f;
 Tone2 ();

 if(strcmp(bar_heating.Caption,"HEATING")==0){
 system_reg[SET_HEAT]++;
 IntToStr(system_reg[SET_HEAT], txt);
 f= system_reg[SET_HEAT];
 }
 else if(strcmp(bar_heating.Caption,"COOLING")==0){
 system_reg[SET_COOL]++;

 IntToStr(system_reg[SET_COOL], txt);
 f= system_reg[SET_COOL];
 }
 Ltrim (txt);
 strncpy(TEMP_Setting_value.Caption , txt, 2);
 if(f<10 && f>=0){TEMP_Setting_value.Caption[1]=TEMP_Setting_value.Caption[0];TEMP_Setting_value.Caption[0]='0';}
 DrawBox(&Set_Heat_Box);
 DrawLabel (&TEMP_Setting_value);
}
void HEAT_DownOnClick(){
 char txt[7];
 int f;
 Tone2 ();
 if(strcmp(bar_heating.Caption,"HEATING")==0){
 system_reg[SET_HEAT]--;
 if(system_reg[SET_HEAT]<system_reg[HEAT_MIN]) system_reg[SET_HEAT]=system_reg[HEAT_MIN];
 IntToStr(system_reg[SET_HEAT], txt);
 f= system_reg[SET_HEAT];
 }
 else if(strcmp(bar_heating.Caption,"COOLING")==0){
 system_reg[SET_COOL]--;
 if(system_reg[SET_COOL]<system_reg[COOL_MIN]) system_reg[SET_COOL]=system_reg[COOL_MIN];
 IntToStr(system_reg[SET_COOL], txt);
 f= system_reg[SET_COOL];
 }
 Ltrim (txt);
 strncpy(TEMP_Setting_value.Caption , txt, 2);
 if(f<10 && f>=0){TEMP_Setting_value.Caption[1]=TEMP_Setting_value.Caption[0];TEMP_Setting_value.Caption[0]='0';}
 DrawBox(&Set_Heat_Box);
 DrawLabel (&TEMP_Setting_value);

}

void user_settingOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image105.Visible = 0;
 DrawScreen(&SYSTEM_EVENTS);
 BLED_Fade_In();
}
void user_settingOnPress(){
 Image105.Visible = 1;
 DrawImage(&Image105);
}
void user_set_timeOnPress(){
 Image39.Visible = 1;
 DrawImage(&Image39);
}
void user_set_timeOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image39.Visible = 0;

 DrawScreen(&SetRTC);
 BLED_Fade_In();
}

void user_check_temperatureOnPress(){
 Image48.Visible = 1;
 DrawImage(&Image48);
}
void user_check_temperatureOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image48.Visible = 0;
 strcpy(S_Brine_Inlet_1.Caption,"00");
 strcpy(S_Brine_Outlet_1.Caption,"00");
 strcpy(S_Heat_Inlet_1.Caption,"00");
 strcpy(S_Heat_Outlet_1.Caption,"00");
 strcpy(S_Compressor_1.Caption ,"000");
 strcpy(S_Superheat_1.Caption,"00");
 strcpy( S_Subcool_1.Caption,"00");
 strcpy(S_DHW.Caption,"00");
 strcpy(SS_tank.Caption,"00");
 strcpy(S_condenser_1.Caption,"00");
 strcpy(S_High_Pressure_1.Caption,"00");
 strcpy(S_Low_Pressure_1.Caption,"00");
 DrawScreen(&SENSOR1);
 BLED_Fade_In();
}
void user_set_LANOnPress(){
 Image49.Visible = 1;
 DrawImage(&Image49);
}
void user_set_LANOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image49.Visible = 0;
 DrawScreen(&Ethernet);
 BLED_Fade_In();
}
void user_check_errorsOnPress(){
 Image50.Visible = 1;
 DrawImage(&Image50);
}
void user_check_errorsOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image50.Visible = 0;
 DrawScreen(&ERRORS);
 BLED_Fade_In();
}
void user_set_timersOnPress(){
 Image51.Visible = 1;
 DrawImage(&Image51);
}
void user_set_timersOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image51.Visible = 0;
 DrawScreen(&TIMERS);
 BLED_Fade_In();
}
void user_hysterezisOnPress(){
 Image60.Visible = 1;
 DrawImage(&Image60);
}
void user_hysterezisOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image60.Visible = 0;
 DrawScreen(&SETTINGS);
 BLED_Fade_In();
}
void User_history_checkOnPress(){
 Image52.Visible = 1;
 DrawImage(&Image52);
}
void User_history_checkOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image52.Visible = 0;
 DrawScreen(&EVENTS);
 BLED_Fade_In();
}

void user_energyOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image54.Visible = 0;
 DrawScreen(&ENERGY);
 BLED_Fade_In();
}
void user_energyOnPress(){
 Image54.Visible = 1;
 DrawImage(&Image54);
}
void admin_set_systemOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image55.Visible = 0;

 DrawScreen (&SYSTEM_SET);
 BLED_Fade_In();
}
void admin_set_systemOnPress (){
 Image55.Visible = 1;
 DrawImage(&Image55);
}
void furnanceUP(){
 Tone2();
 BLED_Fade_Out();
 Image56.Visible = 0;
 DrawScreen(&FURNANCE);
 BLED_Fade_In();
}
void furnanceDown(){
 Image56.Visible = 1;
 DrawImage(&Image56);
}
void user_defrostOnUp(){
 Tone2();
 BLED_Fade_Out();
 Image57.Visible = 0;
 DrawScreen(&DEFROST);
 BLED_Fade_In();
}
void user_defrostOnPress(){
 Image57.Visible = 1;
 DrawImage(&Image57);
}
#line 839 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
void DEC_EEV1OnPress() {
 char txt[7];
 Tone1();
 incTRV--;

 if(incTRV<0)incTRV=0;
 IntToStr(incTRV, txt);Ltrim(txt);
 strcpy(EEV1_value.Caption, txt);
 DrawRoundButton(&EEV1_value);







 Delay_ms (50);

 }
void INC_EEV1OnPress() {
 char txt[7];

 Tone1();
 incTRV++;

 if(incTRV>240)incTRV=240;
 IntToStr(incTRV, txt);Ltrim(txt);
 strcpy(EEV1_value.Caption, txt);
 DrawRoundButton(&EEV1_value);



 Delay_ms (50);

}

void Set_Trv() {
 if(num_page==0)
 {
 system_reg[TRV_CORRECT_1]= incTRV;
 send_data_packet(TRV_CORRECT_1,1);
 }
 else{
 system_reg[TRV_CORRECT_2]= incTRV;
 send_data_packet(TRV_CORRECT_2,1);
 }
}


void _1OnClick() {

}

void _2OnClick() {

}

void _3OnClick() {

}

void _4OnClick() {

}

void _5OnClick() {

}

void _6OnClick() {

}

void _7OnClick() {

}

void _8OnClick() {

}

void _9OnClick() {

}

void _0OnClick() {

}

void _QOnClick() {

}

void _WOnClick() {

}

void _EOnClick() {

}

void _ROnClick() {

}

void _TOnClick() {

}

void _YOnClick() {

}

void _UOnClick() {

}

void _IOnClick() {

}

void _OOnClick() {

}

void _POnClick() {

}

void _AOnClick() {

}

void _SOnClick() {

}

void _DOnClick() {

}

void _FOnClick() {

}

void _GOnClick() {

}

void _HOnClick() {

}

void _JOnClick() {

}

void _KOnClick() {

}

void _LOnClick() {

}

void _ZOnClick() {

}

void _XOnClick() {

}

void _COnClick() {

}

void _VOnClick() {

}

void _BOnClick() {

}

void _NOnClick() {

}

void _MOnClick() {

}

void _CommaOnClick() {

}

void _ColonOnClick() {

}

void _SlashOnClick() {

}

void _DELOnClick() {

}

void ClearOnPress() {

}

void CAPS_SwitchOnClick() {

}

void SPACEOnClick() {

}

void ENTEROnClick() {

}

 void SetDateAndTimeOnClick(){


 My_Date.RTC_Date_Tens = tenDayU;
 My_Date.RTC_Date_Units = oneDayU;
 My_Date.RTC_Month_Tens = oneMonth/10;
 My_Date.RTC_Month_Units = oneMonth%10;
 My_Date.RTC_Year_Tens = oneYearU;
 My_Date.RTC_Year_Units = tenYearU;



 My_Time.RTC_Hour_Tens = tenHour;
 My_Time.RTC_Hour_Units = oneHour;
 My_Time.RTC_Min_Tens = tenMinute;
 My_Time.RTC_Min_Units = oneMinute;



 RTC_SetTime(&My_Time, -37);
 RTC_SetDate(&My_Date);
 }
 void OneYearUpOnClick(){

}
void OneYearDwnOnClick(){

}
void OneYearUpOnUp(){

 char txt[4];
 char *res;
 oneYearU++;
 if (oneYearU > 9)oneYearU=0;
 ByteToStr(oneYearU, txt);
 res=Ltrim(txt);
 strcpy(Button1.Caption,res );
 DrawButton(&Button1);
}
void OneYearUpOnPress(){

}
void OneYearDwnOnUp() {
 char txt[4];
 char *res;
 oneYearU--;
 if (oneYearU >9)oneYearU=0;
 ByteToStr(tenYearU, txt);
 res = Ltrim(txt);
 strcpy(Button1.Caption, res);
 DrawButton(&Button1);
}
void OneYearDwnOnPress() {

}

void TenYearUpOnClick() {

}
void TenYearDwnOnClick() {

}
void TenYearUpOnUp() {
 char txt[4];
 char *res;
 tenYearU++;
 if (tenYearU > 9)tenYearU=0;
 ByteToStr(tenYearU, txt);
 res =Ltrim(txt);
 strcpy(Button3.Caption,res);
 DrawButton(&Button3);
}
void TenYearDwnOnUp() {
 char txt[4];
 char *res;
 tenYearU--;
 if (tenYearU > 9)tenYearU=0;
 ByteToStr(tenYearU, txt);
 res = Ltrim(txt);
 strcpy(Button3.Caption,res);
 DrawButton(&Button3);
}
void TenYearDwnOnPress() {
}
void TenYearUpOnPress() {

}

void MonthDateUpOnClick() {

}
void MonthDateUpOnUp() {


 oneMonth++;
 if (oneMonth > 12)oneMonth=1;
switch (oneMonth) {
 case 1 : strcpy(Button4.Caption,"JAN");break;
 case 2 : strcpy(Button4.Caption,"FAB");break;
 case 3 : strcpy(Button4.Caption,"MAR");break;
 case 4 : strcpy(Button4.Caption,"APR");break;
 case 5 : strcpy(Button4.Caption,"MAY");break;
 case 6 : strcpy(Button4.Caption,"JUN");break;
 case 7 : strcpy(Button4.Caption,"JUL");break;
 case 8 : strcpy(Button4.Caption,"AUG");break;
 case 9 : strcpy(Button4.Caption,"SEP");break;
 case 10 : strcpy(Button4.Caption,"OCT");break;
 case 11 : strcpy(Button4.Caption,"NOV");break;
 case 12 : strcpy(Button4.Caption,"DEC");break;
 }

 DrawButton(&Button4);
}
void MonthDateUpOnPress() {

}
void MonthDateDwnOnClick() {




}
void MonthDateDwnOnUp() {

 oneMonth--;
 if (oneMonth > 12)oneMonth=1;
 strcpy(Button4.Caption,"SEP");
 switch (oneMonth) {
 case 1 : strcpy(Button4.Caption,"JAN");break;
 case 2 : strcpy(Button4.Caption,"FAB");break;
 case 3 : strcpy(Button4.Caption,"MAR");break;
 case 4 : strcpy(Button4.Caption,"APR");break;
 case 5 : strcpy(Button4.Caption,"MAY");break;
 case 6 : strcpy(Button4.Caption,"JUN");break;
 case 7 : strcpy(Button4.Caption,"JUL");break;
 case 8 : strcpy(Button4.Caption,"AUG");break;
 case 9 : strcpy(Button4.Caption,"SEP");break;
 case 10 : strcpy(Button4.Caption,"OCT");break;
 case 11 : strcpy(Button4.Caption,"NOV");break;
 case 12 : strcpy(Button4.Caption,"DEC");break;
 }
 DrawButton(&Button4);
}
void MonthDateDwnOnPress() {
}

void TenDayUpOnClick() {

}
void TenDayDwnOnClick() {

}

void TenDayUpOnUp() {
 char txt[4];
 tenDayU++;
 if (tenDayU > 9)tenDayU=0;
 ByteToStr(tenDayU, txt);
 strcpy(Button8.Caption,Ltrim(txt));
 DrawButton(&Button8);
}

void TenDayDwnOnUp() {
 char txt[4];
 tenDayU--;
 if (tenDayU > 9)tenDayU=0;
 ByteToStr(tenDayU, txt);
 strcpy(Button8.Caption,Ltrim(txt));
 DrawButton(&Button8);
}

void TenDayUpOnPress() {

}

void TenDayDwnOnPress() {

}

void OneDayUpOnClick() {

}

void OneDayDwnOnClick() {

}

void OneDayUpOnUp() {
 char txt[4];
 oneDayU++;
 if (oneDayU > 9)oneDayU=0;
 ByteToStr(oneDayU, txt);
 strcpy(Button12.Caption,Ltrim(txt));
 DrawButton(&Button12);
}

void OneDayDwnOnUp() {
 char txt[4];
 oneDayU--;
 if (oneDayU > 9)oneDayU=0;
 ByteToStr(oneDayU, txt);
 strcpy(Button12.Caption,Ltrim(txt));
 DrawButton(&Button12);
}

void OneDayUpOnPress() {

}

void OneDayDwnOnPress() {

}

void Day_unitUpOnClick() {

}

void Day_unitDwnOnClick() {

}

void Day_unitUpOnUp() {
 char txt[4];
 tenHour++;
 if (tenHour > 9)tenHour=0;
 ByteToStr(tenHour, txt);
 strcpy(Button21.Caption,Ltrim(txt));
 DrawButton(&Button21);
}

void Day_unitDwnOnUp() {
 char txt[4];
 tenHour--;
 if (tenHour > 9)tenHour=0;
 ByteToStr(tenHour, txt);
 strcpy(Button21.Caption,Ltrim(txt));
 DrawButton(&Button21);
}

void Day_unitUpOnPress() {

}

void Day_unitDwnOnPress() {

}

void Unit_hoursUpOnClick() {

}

void Unit_hoursDwnOnClick() {

}
void Unit_hoursUpOnUp() {
 char txt[4];
 oneHour++;
 if (oneHour > 9)oneHour=0;
 ByteToStr(oneHour, txt);
 strcpy(Button24.Caption,Ltrim(txt));
 DrawButton(&Button24);
 }
void Unit_hoursDwnOnUp() {
 char txt[4];
 oneHour--;
 if (oneHour > 9)oneHour=0;
 ByteToStr(oneHour, txt);
 strcpy(Button24.Caption,Ltrim(txt));
 DrawButton(&Button24);
}
void Unit_hoursUpOnPress() {

}
void Unit_hoursDwnOnPress() {

}

void Ten_minutesUpOnClick() {

}
void Ten_minutesDwnOnClick() {

}
void Ten_minutesUpOnUp() {
 char txt[4];
 tenMinute++;
 if (tenMinute > 9)tenMinute=0;
 ByteToStr(tenMinute, txt);
 strcpy(Button40.Caption,Ltrim(txt));
 DrawButton(&Button40);
}
void Ten_minutesDwnOnUp() {
 char txt[4];
 tenMinute--;
 if (tenMinute > 9)tenMinute=0;
 ByteToStr(tenMinute, txt);
 strcpy(Button40.Caption,Ltrim(txt));
 DrawButton(&Button40);
}
void Ten_minutesUpOnPress() {

}
void Ten_minutesDwnOnPress() {

}

void Unit_minutesUpOnClick() {

}

void Unit_minutesDwnOnClick() {

}

void Unit_minutesUpOnUp(){
 char txt[4];
 oneMinute++;
 if (oneMinute > 9)oneMinute=0;
 ByteToStr(oneMinute, txt);
 strcpy(Button43.Caption,Ltrim(txt));
 DrawButton(&Button43);
}

void Unit_minutesDwnOnUp(){
 char txt[4];
 oneMinute--;
 if (oneMinute > 9)oneMinute=0;
 ByteToStr(oneMinute, txt);
 strcpy(Button43.Caption,Ltrim(txt));
 DrawButton(&Button43);
}

void Unit_minutesUpOnPress() {

}

void Unit_minutesDwnOnPress() {

}


 void Admin_SetOnClick(){
 }

 void system_passOnDown() {
 Image83.Visible = 1;
 DrawImage(&Image83);
}

void system_passOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image83.Visible = 0;
 DrawScreen(&PASSWORD);
 BLED_Fade_In();
}

void ModeSetOnUp() {
 if (SYSTEM_ON ==  0 ) {
 BLED_Fade_Out();
 strcpy(System_Set_Message.Caption, " ");
 Image300.Visible = 0;
 System_Set_Message.Visible = 0;
 BLED_Fade_In();
 }
 else {
 strcpy(System_Set_Message.Caption, "Please  OFF  system  power!");
 Image300.Visible = 1;
 DrawImage (&Image300);
 System_Set_Message.Visible = 1;
 DrawButton (&System_Set_Message);
 }
}

void ModeSetOnDown() {
 Image85.Visible = 1;
 DrawImage(&Image85);
}

void system_EEVOnDown() {
 Image89.Visible = 1;
 DrawImage(&Image89);
 reciev_data_packet(TRV_CORRECT_1,1);
 Delay_ms(300);
}

void system_EEVOnUp() {
 char txt[7];
 Tone2();
 BLED_Fade_Out();
 incTRV = system_reg[TRV_CORRECT_1];
 IntToStr(incTRV, txt);Ltrim(txt);
 strcpy(EEV1_value.Caption, txt);
 Image89.Visible = 0;
 DrawScreen(&EEV);
 BLED_Fade_In();

}

void system_modeOnDown() {
 Image85.Visible = 1;
 DrawImage(&Image85);
}

void system_modeOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image85.Visible = 0;
 DrawScreen(&MODE);
 BLED_Fade_In();
}

void system_delayOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image90.Visible = 0;
 DrawScreen(&DELAY_MENU);
 BLED_Fade_In();
}
void system_delayOnDown() {
 Image90.Visible = 1;
 DrawImage(&Image90);
}

void system_graphOnDown() {
 Tone2();
 BLED_Fade_Out();
 Image90.Visible = 0;
 DrawScreen(&Graph);
 BLED_Fade_In();
}

void system_graphOnUp() {
 Image92.Visible = 1;
 DrawImage(&Image92);

}
void system_microSDOnDown() {
 Image88.Visible = 1;
 DrawImage(&Image88);
}

void system_microSDOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image88.Visible = 0;
 DrawScreen(&MICRO_SD);
 BLED_Fade_In();
}


void system_limitsOnDown() {
 Image91.Visible = 1;
 DrawImage(&Image91);
}

void system_limitsOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image91.Visible = 0;
 DrawScreen(&LIMITS1);
 BLED_Fade_In();
}

void ssytem_graphOnDown() {
 Image92.Visible = 1;
 DrawImage(&Image92);
}

void ssytem_graphOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image92.Visible = 0;
 DrawScreen(&Graph);
 BLED_Fade_In();
}

void system_historyOnDown() {
 Image93.Visible = 1;
 DrawImage(&Image93);
}

void system_historyOnUp() {
 Tone2();
 BLED_Fade_Out();
 Image93.Visible = 0;
 DrawScreen(&SYSTEM_EVENTS);
 BLED_Fade_In();
}


void Delay_Source_DOWNOnUp() {
 Image306.Visible = 0;
 Delay_Source_DOWN.Visible = 1;
 DrawImage(&Delay_Source_DOWN);
}
void Delay_Source_DOWNOnPress() {

 char txt[7];
 Tone2 ();
 Image306.Visible = 1;
 Delay_Source_DOWN.Visible = 0;
 DrawImage(&Image306);


 system_reg[SOURS_DEL]--;
 if (system_reg[SOURS_DEL] <0) system_reg[SOURS_DEL]=0;
 IntToStr(system_reg[SOURS_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_Source.Caption, txt, 2);
 DrawRoundButton(&Delay_Source);
 Delay_ms (100);
}
void Delay_Source_UPOnUp() {
 Image312.Visible = 0;
 Delay_Source_UP.Visible = 1;
 DrawImage(&Delay_Source_UP);

}
void Delay_Source_UPOnPress() {

 char txt[7];
 Tone2 ();
 Image312.Visible = 1;
 Delay_Source_UP.Visible = 0;
 DrawImage(&Image312);
 system_reg[SOURS_DEL]++;
 if (system_reg[SOURS_DEL] >99) system_reg[SOURS_DEL] = 99;
 IntToStr(system_reg[SOURS_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_Source.Caption, txt, 2);
 DrawRoundButton(&Delay_Source);
 Delay_ms (100);
}
void Delay_Source_SETOnUp() {
 Delay_Source_SET.Visible = 1;
 Image344.Visible = 0;
 DrawImage (&Delay_Source_SET);
}
void Delay_Source_SETOnDown() {
 Tone1();
#line 1608 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(SOURS_DEL,1);
 Delay_Source_SET.Visible = 0;
 Image344.Visible = 1;
 DrawImage (&Image344);
}

void Delay_heat_pump_DOWNOnUp() {
 Image307.Visible = 0;
 Delay_heat_pump_DOWN.Visible = 1;
 DrawImage(&Delay_heat_pump_DOWN);

}
void Delay_heat_pump_DOWNOnPress() {

 char txt[7];
 Tone2 ();
 Image307.Visible = 1;
 Delay_heat_pump_DOWN.Visible = 0;
 DrawImage(&Image307);
#line 1629 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[HEAT_DEL]--;
 if (system_reg[HEAT_DEL] <0) system_reg[HEAT_DEL]=0;
 IntToStr(system_reg[HEAT_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_heat_pump.Caption, txt, 2);
 DrawRoundButton(&Delay_heat_pump);
 Delay_ms (100);
}
void Delay_heat_pump_upOnUp() {
 Image313.Visible = 0;
 Delay_heat_pump_up.Visible = 1;
 DrawImage(&Delay_heat_pump_up);
}
void Delay_heat_pump_upOnPress() {

 char txt[7];
 Tone2 ();
 Image313.Visible = 1;
 Delay_heat_pump_up.Visible = 0;
 DrawImage(&Image313);
#line 1651 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[HEAT_DEL]++;
 if (system_reg[HEAT_DEL] >99)
 system_reg[HEAT_DEL] = 99;
 IntToStr(system_reg[HEAT_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_heat_pump.Caption, txt, 2);
 DrawRoundButton(&Delay_heat_pump);
 Delay_ms (100);

}
void Delay_heat_pump_SETOnUp() {
 Delay_heat_pump_SET.Visible = 1;
 Image345.Visible = 0;
 DrawImage (&Delay_heat_pump_SET);
}
void Delay_heat_pump_SETOnDown() {
 Tone1();
#line 1671 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(HEAT_DEL,1);
 Delay_heat_pump_SET.Visible = 0;
 Image345.Visible = 1;
 DrawImage (&Image345);
}

void Delay_reversing_DOWNOnUp() {
 Image308.Visible = 0;
 Delay_reversing_DOWN.Visible = 1;
 DrawImage(&Delay_reversing_DOWN);
}
void Delay_reversing_DOWNOnPress() {

 char txt[7];
 Tone2 ();
 Image308.Visible = 1;
 Delay_reversing_DOWN.Visible = 0;
 DrawImage(&Image308);
#line 1691 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[REVERS_DEL]--;
 if (system_reg[REVERS_DEL] <0)
 system_reg[REVERS_DEL] = 0;
 IntToStr(system_reg[REVERS_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_reversing.Caption, txt, 2);
 DrawRoundButton(&Delay_reversing);
 Delay_ms (100);
}
void Delay_reversing_UPOnUp() {
 Image314.Visible = 0;
 Delay_reversing_UP.Visible = 1;
 DrawImage(&Delay_reversing_UP);
}
void Delay_reversing_UPOnPress() {

 char txt[7];
 Tone2 ();
 Image314.Visible = 1;
 Delay_reversing_UP.Visible = 0;
 DrawImage(&Image314);
#line 1714 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[REVERS_DEL]++;
 if (system_reg[REVERS_DEL] >99)
 system_reg[REVERS_DEL] = 99 ;
 IntToStr(system_reg[REVERS_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_reversing.Caption, txt, 2);
 DrawRoundButton(&Delay_reversing);
 Delay_ms (100);
}
void Delay_reversing_SETOnUp() {
 Delay_reversing_SET.Visible = 1;
 Image346.Visible = 0;
 DrawImage (&Delay_reversing_SET);
}
void Delay_reversing_SETOnDown() {
 Tone1();
#line 1733 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(REVERS_DEL,1);
 Delay_reversing_SET.Visible = 0;
 Image346.Visible = 1;
 DrawImage (&Image346);
}

void Delay_trv_DOWNOnUp() {
 Image309.Visible = 0;
 Delay_trv_DOWN.Visible = 1;
 DrawImage(&Delay_trv_DOWN);
}
void Delay_trv_DOWNOnPress() {

 char txt[7];
 Tone2 ();
 Image309.Visible = 1;
 Delay_trv_DOWN.Visible = 0;
 DrawImage(&Image309);
#line 1753 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[TRV_DEL]--;
 if (system_reg[TRV_DEL] < 0)
 system_reg[TRV_DEL] = 0;
 IntToStr(system_reg[TRV_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_EEV.Caption, txt, 2);
 DrawRoundButton(&Delay_EEV);
 Delay_ms (100);
}
void Delay_trv_UPOnUp() {
 Image315.Visible = 0;
 Delay_trv_up.Visible = 1;
 DrawImage(&Delay_trv_up);
}
void Delay_trv_UPOnPress(){

 char txt[7];
 Tone2 ();
 Image315.Visible = 1;
 Delay_trv_up.Visible = 0;
 DrawImage(&Image315);
#line 1776 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[TRV_DEL]++;
 if (system_reg[TRV_DEL] >99)
 system_reg[TRV_DEL] = 99;
 IntToStr(system_reg[TRV_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_EEV.Caption, txt, 2);
 DrawRoundButton(&Delay_EEV);
 Delay_ms (100);
}
void Delay_EEV_SETOnUp() {
 Delay_EEV_SET.Visible = 1;
 Image347.Visible = 0;
 DrawImage (&Delay_EEV_SET);
}
void Delay_EEV_SETOnDown() {
 Tone1();
#line 1795 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(TRV_DEL,1);
 Delay_EEV_SET.Visible = 0;
 Image347.Visible = 1;
 DrawImage (&Image347);
}

void Delay_DHW_valve_DOWNOnUp() {
 Image310.Visible = 0;
 Delay_DHW_valve_DOWN.Visible = 1;
 DrawImage(&Delay_DHW_valve_DOWN);
}
void Delay_DHW_valve_DOWNOnPress() {

 char txt[7];
 Tone2 ();
 Image310.Visible = 1;
 Delay_DHW_valve_DOWN.Visible = 0;
 DrawImage(&Image310);
#line 1815 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[THREE_WAY_DEL]--;
 if (system_reg[THREE_WAY_DEL] < 0)
 system_reg[THREE_WAY_DEL] = 0;
 IntToStr(system_reg[THREE_WAY_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_DHW_valve.Caption, txt, 2);
 DrawRoundButton(&Delay_DHW_valve);
 Delay_ms (100);
}
void Delay_DHW_valve_UPOnUp() {
 Image316.Visible = 0;
 Delay_DHW_valve_UP.Visible = 1;
 DrawImage(&Delay_DHW_valve_UP);
}
void Delay_DHW_valve_UPOnPress() {

 char txt[7];
 Tone2 ();
 Image316.Visible = 1;
 Delay_DHW_valve_UP.Visible = 0;
 DrawImage(&Image316);
#line 1838 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[THREE_WAY_DEL]++;
 if (system_reg[THREE_WAY_DEL] >99)
 system_reg[THREE_WAY_DEL] = 99;
 IntToStr(system_reg[THREE_WAY_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_DHW_valve.Caption, txt, 2);
 DrawRoundButton(&Delay_DHW_valve);
 Delay_ms (100);
}
void Delay_DHW_valve_SETOnUp() {
 Delay_DHW_valve_SET.Visible = 1;
 Image348.Visible = 0;
 DrawImage (&Delay_DHW_valve_SET);
}
void Delay_DHW_valve_SETOnDown() {
 Tone1();
#line 1857 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(THREE_WAY_DEL,1);
 Delay_DHW_valve_SET.Visible = 0;
 Image348.Visible = 1;
 DrawImage (&Image348);
}

void Delay_compressor_DOWNOnUp() {
 Image311.Visible = 0;
 Delay_compressor_DOWN.Visible = 1;
 DrawImage(&Delay_compressor_DOWN);
}
void Delay_compressor_DOWNOnPress() {

 char txt[7];
 Tone2 ();
 Image311.Visible = 1;
 Delay_compressor_DOWN.Visible = 0;
 DrawImage(&Image311);
#line 1877 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[COMP_DEL]--;
 if (system_reg[COMP_DEL] < 0)
 system_reg[COMP_DEL] = 0;
 IntToStr(system_reg[COMP_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_compressor.Caption, txt, 2);
 DrawRoundButton(&Delay_compressor);
 Delay_ms (100);
}
void Delay_compressor_UPOnUp() {
 Image317.Visible = 0;
 Delay_compressor_UP.Visible = 1;
 DrawImage(&Delay_compressor_UP);
}
void Delay_compressor_UPOnPress() {

 char txt[7];
 Tone2 ();
 Image317.Visible = 1;
 Delay_compressor_UP.Visible = 0;
 DrawImage(&Image317);
#line 1900 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 system_reg[COMP_DEL]++;
 if (system_reg[COMP_DEL] >99)
 system_reg[COMP_DEL] = 99;
 IntToStr(system_reg[COMP_DEL], txt);
 Ltrim (txt);
 strncpy(Delay_compressor.Caption, txt, 2);
 DrawRoundButton(&Delay_compressor);
 Delay_ms (100);
}
void Delay_compressor_SETOnUp() {
 Delay_compressor_SET.Visible = 1;
 Image349.Visible = 0;
 DrawImage (&Delay_compressor_SET);
}
void Delay_compressor_SETOnDown() {
 Tone1();
#line 1919 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(COMP_DEL,1);
 Delay_compressor_SET.Visible = 0;
 Image349.Visible = 1;
 DrawImage (&Image349);
}


void Down_1_OnUp() {
 Image200.Visible = 0;
 Down_1_.Visible = 1;
 DrawImage(&Down_1_);
}
void Down_1_OnPress() {
 char txt[7];
 Tone3 ();
 Image200.Visible = 1;
 Down_1_.Visible = 0;
 DrawImage(&Image200);
 system_reg[HEAT_MIN]--;
 if (system_reg[HEAT_MIN] < 0)
 system_reg[HEAT_MIN] = 0;
 IntToStr(system_reg[HEAT_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_heating_HP.Caption, txt, 2);
 DrawRoundButton(&Set_min_heating_HP);
 Delay_ms (100);
}
void Up_1_OnUp() {
 Image218.Visible = 0;
 Up_1_.Visible = 1;
 DrawImage(&Up_1_);
}
void Up_1_OnPress() {
 char txt[7];
 Tone2();
 Image218.Visible = 1;
 Up_1_.Visible = 0;
 DrawImage(&Image218);
 system_reg[HEAT_MIN]++;
 if (system_reg[HEAT_MIN] >99)
 system_reg[HEAT_MIN] = 99;
 IntToStr(system_reg[HEAT_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_heating_HP.Caption, txt, 2);
 DrawRoundButton(&Set_min_heating_HP);
 Delay_ms (100);
}
void Down_2_OnUp() {
 Image205.Visible = 0;
 Down_2_.Visible = 1;
 DrawImage(&Down_2_);
}

void Down_2_OnPress() {
 char txt[7];
 Tone3 ();
 Image205.Visible = 1;
 Down_2_.Visible = 0;
 DrawImage(&Image205);

 system_reg[HEAT_MAX]--;
 if (system_reg[HEAT_MAX] < 0)
 system_reg[HEAT_MAX] = 0;
 IntToStr(system_reg[HEAT_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_heating_HP.Caption, txt, 2);
 DrawRoundButton(&Set_max_heating_HP);
 Delay_ms (100);
}
void Up_2_OnPress() {
 char txt[7];
 Tone2 ();
 Image219.Visible = 1;
 Up_2_.Visible = 0;
 DrawImage(&Image219);

 system_reg[HEAT_MAX]++;
 if (system_reg[HEAT_MAX] >99)
 system_reg[HEAT_MAX] = 99;
 IntToStr(system_reg[HEAT_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_heating_HP.Caption, txt, 2);
 DrawRoundButton(&Set_max_heating_HP);
 Delay_ms (100);
}
void Up_2_OnUp() {
 Image219.Visible = 0;
 Up_2_.Visible = 1;
 DrawImage(&Up_2_);
}

void Down_3_OnPress() {
 char txt[7];
 Tone3 ();
 Image206.Visible = 1;
 Down_3_.Visible = 0;
 DrawImage(&Image206);

 system_reg[EXAUST_MAX]--;
 if (system_reg[EXAUST_MAX] < 0)
 system_reg[EXAUST_MAX] = 0;
 IntToStr(system_reg[EXAUST_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_exhaust.Caption, txt, 3);
 DrawRoundButton(&Set_max_exhaust);
 Delay_ms (100);
}
void Down_3_OnUp() {
 Image206.Visible = 0;
 Down_3_.Visible = 1;
 DrawImage(&Down_3_);
}
void Up_3_OnPress() {
 char txt[7];
 Tone2 ();
 Image220.Visible = 1;
 Up_3_.Visible = 0;
 DrawImage(&Image220);
 system_reg[EXAUST_MAX]++;
 if(system_reg[EXAUST_MAX]>115)
 system_reg[EXAUST_MAX] = 115;
 IntToStr(system_reg[EXAUST_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_exhaust.Caption, txt, 3);
 DrawRoundButton(&Set_max_exhaust);
 Delay_ms (100);
}
void Up_3_OnUp() {
 Image220.Visible = 0;
 Up_3_.Visible = 1;
 DrawImage(&Up_3_);
}
void Down_4_OnPress() {
 char txt[7];
 Tone3 ();
 Image207.Visible = 1;
 Down_4_.Visible = 0;
 DrawImage(&Image207);

 system_reg[SOURS_MIN]--;
 if (system_reg[SOURS_MIN] < -30)
 system_reg[SOURS_MIN] = -30;
 IntToStr(system_reg[SOURS_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_source_temp.Caption, txt, 3);
 DrawRoundButton(&Set_min_source_temp);
 Delay_ms (100);
}
void Up_4_OnPress(){
 char txt[7];
 Tone2 ();
 Image221.Visible = 1;
 Up_4_.Visible = 0;
 DrawImage(&Image221);

 system_reg[SOURS_MIN]++;
 if (system_reg[SOURS_MIN] >99)
 system_reg[SOURS_MIN] = 99;
 IntToStr(system_reg[SOURS_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_source_temp.Caption, txt, 3);
 DrawRoundButton(&Set_min_source_temp);
 Delay_ms (100);

}
void Down_4_OnUp() {
 Image207.Visible = 0;
 Down_4_.Visible = 1;
 DrawImage(&Down_4_);
}
void Up_4_OnUp() {
 Image221.Visible = 0;
 Up_4_.Visible = 1;
 DrawImage(&Up_4_);
}
void Down_5_OnUp() {
 Image208.Visible = 0;
 Down_5_.Visible = 1;
 DrawImage(&Down_5_);
}
void Down_5_OnPress(){
 char txt[7];
 Tone3 ();
 Image208.Visible = 1;
 Down_5_.Visible = 0;
 DrawImage(&Image208);
 system_reg[SOURS_MAX]--;
 if (system_reg[SOURS_MAX] < 0)
 system_reg[SOURS_MAX] = 0;
 IntToStr(system_reg[SOURS_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_source_temp.Caption, txt, 2);
 DrawRoundButton(&Set_max_source_temp);
 Delay_ms (100);
}
void Up_5_OnPress() {
 char txt[7];
 Tone2 ();
 Image222.Visible = 1;
 Up_5_.Visible = 0;
 DrawImage(&Image222);
 system_reg[SOURS_MAX]++;
 if (system_reg[SOURS_MAX] >99)
 system_reg[SOURS_MAX] = 99;
 IntToStr(system_reg[SOURS_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_source_temp.Caption, txt, 2);
 DrawRoundButton(&Set_max_source_temp);
 Delay_ms (100);
}
void Up_5_OnUp() {
 Image222.Visible = 0;
 Up_5_.Visible = 1;
 DrawImage(&Up_5_);
}
void Down_6_OnPress() {
 char txt[7];
 Tone3 ();
 Image209.Visible = 1;
 Down_6_.Visible = 0;
 DrawImage(&Image209);
 system_reg[DEL_HEAT_MIN]--;
 if (system_reg[DEL_HEAT_MIN] < 0)
 system_reg[DEL_HEAT_MIN] = 0;
 IntToStr(system_reg[DEL_HEAT_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_delta_heat.Caption, txt, 2);
 DrawRoundButton(&Set_min_delta_heat);
 Delay_ms (100);
}
void Down_6_OnUp() {
 Image209.Visible = 0;
 Down_6_.Visible = 1;
 DrawImage(&Down_6_);
}
void Up_6_OnPress() {
 char txt[7];
 Tone2 ();
 Image223.Visible = 1;
 Up_6_.Visible = 0;
 DrawImage(&Image223);
 system_reg[DEL_HEAT_MIN]++;
 if (system_reg[DEL_HEAT_MIN] >99)
 system_reg[DEL_HEAT_MIN] = 99;
 IntToStr(system_reg[DEL_HEAT_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_delta_heat.Caption, txt, 2);
 DrawRoundButton(&Set_min_delta_heat);
 Delay_ms (100);
}
void Up_6_OnUp() {
 Image223.Visible = 0;
 Up_6_.Visible = 1;
 DrawImage(&Up_6_);
}
void Set_1_OnDown() {
 Tone1();
#line 2179 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(HEAT_MIN,1);
 Set_1_.Visible = 0;
 Image246.Visible = 1;
 DrawImage (&Image246);
}
void Set_1_OnUp() {
 Set_1_.Visible = 1;
 Image246.Visible = 0;
 DrawImage (&Set_1_);
}
void Set_2_OnDown() {
 Tone1();
#line 2194 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(HEAT_MAX,1);
 Set_2_.Visible = 0;
 Image247.Visible = 1;
 DrawImage (&Image247);
}
void Set_2_OnUp(){
 Set_2_.Visible = 1;
 Image247.Visible = 0;
 DrawImage (&Set_2_);
}

void Set_3_OnDown() {
 Tone1();
#line 2210 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(EXAUST_MAX,1);
 Set_3_.Visible = 0;
 Image248.Visible = 1;
 DrawImage (&Image248);
}
void Set_3_OnUp() {
 Set_3_.Visible = 1;
 Image248.Visible = 0;
 DrawImage (&Set_3_);
}
void Set_4_OnDown() {
 Tone1();
#line 2225 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(SOURS_MIN,1);
 Set_4_.Visible = 0;
 Image249.Visible = 1;
 DrawImage (&Image249);
 }

void Set_4_OnUp() {
 Set_4_.Visible = 1;
 Image249.Visible = 0;
 DrawImage (&Set_4_);
}

void Set_5_OnDown() {
 Tone1();
#line 2242 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(SOURS_MAX,1);
 Set_5_.Visible = 0;
 Image250.Visible = 1;
 DrawImage (&Image250);
}
void Set_5_OnUp() {
 Set_5_.Visible = 1;
 Image250.Visible = 0;
 DrawImage (&Set_5_);
}
void Furnance_HP_OFF_save_ondown() {

}
 void Set_6_OnUp() {
 Set_6_.Visible = 1;
 Image251.Visible = 0;
 DrawImage (&Set_6_);
}
void Set_6_OnDown(){
 Tone1();
#line 2265 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(DEL_HEAT_MIN,1);
 Set_6_.Visible = 0;
 Image251.Visible = 1;
 DrawImage (&Image251);
}

 void Down_7_OnUp() {
 Image210.Visible = 0;
 Down_7_.Visible = 1;
 DrawImage(&Down_7_);
}
void Down_7_OnPress(){
 char txt[7];
 Tone3 ();
 Image210.Visible = 1;
 Down_7_.Visible = 0;
 DrawImage(&Image210);
 system_reg[DEL_HEAT_MAX]--;
 if (system_reg[DEL_HEAT_MAX] < 0)
 system_reg[DEL_HEAT_MAX] = 0;
 IntToStr(system_reg[DEL_HEAT_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_delta_heat.Caption, txt, 2);
 DrawRoundButton(&Set_max_delta_heat);
 Delay_ms (100);
}

void Up_7_OnPress() {
 char txt[7];
 Tone2 ();
 Image224.Visible = 1;
 Up_7_.Visible = 0;
 DrawImage(&Image224);
 system_reg[DEL_HEAT_MAX]++;
 if (system_reg[DEL_HEAT_MAX] >99)
 system_reg[DEL_HEAT_MAX] = 99;
 IntToStr(system_reg[DEL_HEAT_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_delta_heat.Caption, txt, 2);
 DrawRoundButton(&Set_max_delta_heat);
 Delay_ms (100);

}

void Up_7_OnUp() {
 Image224.Visible = 0;
 Up_7_.Visible = 1;
 DrawImage(&Up_7_);

}

void Down_8_OnPress() {
 char txt[7];
 Tone3 ();
 Image211.Visible = 1;
 Down_8_.Visible = 0;
 DrawImage(&Image211);
 system_reg[DEL_DHW_MIN]--;
 if (system_reg[DEL_DHW_MIN] < 0)
 system_reg[DEL_DHW_MIN] = 0;
 IntToStr(system_reg[DEL_DHW_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_delta_DHW.Caption, txt, 2);
 DrawRoundButton(&Set_min_delta_DHW);
 Delay_ms (100);
}

void Down_8_OnUp() {
 Image211.Visible = 0;
 Down_8_.Visible = 1;
 DrawImage(&Down_8_);
}

void Up_8_OnPress() {
 char txt[7];
 Tone2 ();
 Image225.Visible = 1;
 Up_8_.Visible = 0;
 DrawImage(&Image225);
 system_reg[DEL_DHW_MIN]++;
 if (system_reg[DEL_DHW_MIN] >99)
 system_reg[DEL_DHW_MIN] = 99;
 IntToStr(system_reg[DEL_DHW_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_delta_DHW.Caption, txt, 2);
 DrawRoundButton(&Set_min_delta_DHW);
 Delay_ms (100);
}

void Up_8_OnUp() {
 Image225.Visible = 0;
 Up_8_.Visible = 1;
 DrawImage(&Up_8_);
}

 void Down_9_OnPress() {
 char txt[7];
 Tone3 ();
 Image214.Visible = 1;
 Down_9_.Visible = 0;
 DrawImage(&Image214);
 system_reg[DEL_DHW_MAX]--;
 if (system_reg[DEL_DHW_MAX] < 0)
 system_reg[DEL_DHW_MAX] = 0;
 IntToStr(system_reg[DEL_DHW_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_delta_DHW.Caption, txt, 2);
 DrawRoundButton(&Set_max_delta_DHW);
 Delay_ms (100);
}

void Down_9_OnUp() {
 Image214.Visible = 0;
 Down_9_.Visible = 1;
 DrawImage(&Down_9_);
}

void Up_9_OnPress() {
 char txt[7];
 Tone2 ();
 Image228.Visible = 1;
 Up_9_.Visible = 0;
 DrawImage(&Image228);
 system_reg[DEL_DHW_MAX]++;
 if (system_reg[DEL_DHW_MAX] > 99)
 system_reg[DEL_DHW_MAX] = 99;
 IntToStr(system_reg[DEL_DHW_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_delta_DHW.Caption, txt, 2);
 DrawRoundButton(&Set_max_delta_DHW);
 Delay_ms (100);
}

void Up_9_OnUp() {
 Image228.Visible = 0;
 Up_9_.Visible = 1;
 DrawImage(&Up_9_);
}
 void Down_10_OnPress() {
 char txt[7];
 Tone3 ();
 Image212.Visible = 1;
 Down_10_.Visible = 0;
 DrawImage(&Image212);
 system_reg[DEL_SOURS_MIN]--;
 if (system_reg[DEL_SOURS_MIN] < 0)
 system_reg[DEL_SOURS_MIN] = 0;
 IntToStr(system_reg[DEL_SOURS_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_delta_source.Caption, txt, 2);
 DrawRoundButton(&Set_min_delta_source);
 Delay_ms (100);
}

void Down_10_OnUp() {
 Image212.Visible = 0;
 Down_10_.Visible = 1;
 DrawImage(&Down_10_);
}

void Up_10_OnPress() {
 char txt[7];
 Tone2 ();
 Image226.Visible = 1;
 Up_10_.Visible = 0;
 DrawImage(&Image226);
 system_reg[DEL_SOURS_MIN]++;
 if (system_reg[DEL_SOURS_MIN] >99)
 system_reg[DEL_SOURS_MIN] = 99;
 IntToStr(system_reg[DEL_SOURS_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_delta_source.Caption, txt, 2);
 DrawRoundButton(&Set_min_delta_source);
 Delay_ms (100);
}

void Up_10_OnUp() {
 Image226.Visible = 0;
 Up_10_.Visible = 1;
 DrawImage(&Up_10_);
}
void Down_11_OnPress() {
 char txt[7];
 Tone3 ();
 Image213.Visible = 1;
 Down_11_.Visible = 0;
 DrawImage(&Image213);
 system_reg[DEL_SOURS_MAX]--;
 if (system_reg[DEL_SOURS_MAX] < 0)
 system_reg[DEL_SOURS_MAX] = 0;
 IntToStr(system_reg[DEL_SOURS_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_source_delta.Caption, txt, 2);
 DrawRoundButton(&Set_max_source_delta);
 Delay_ms (100);
}

void Down_11_OnUp() {
 Image213.Visible = 0;
 Down_11_.Visible = 1;
 DrawImage(&Down_11_);

}

void Up_11_OnPress() {
 char txt[7];
 Tone2 ();
 Image227.Visible = 1;
 Up_11_.Visible = 0;
 DrawImage(&Image227);
 system_reg[DEL_SOURS_MAX]++;
 if (system_reg[DEL_SOURS_MAX] >99)
 system_reg[DEL_SOURS_MAX] = 99;
 IntToStr(system_reg[DEL_SOURS_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_source_delta.Caption, txt, 2);
 DrawRoundButton(&Set_max_source_delta);
 Delay_ms (100);
}

void Up_11_OnUp() {
 Image227.Visible = 0;
 Up_11_.Visible = 1;
 DrawImage(&Up_11_);
}




void Down_12_OnPress() {

}

void Down_12_OnUp() {

}

void Up_12_OnPress() {

}

void Up_12_OnUp() {

}
void Set_7_OnUp() {
 Set_7_.Visible = 1;
 Image252.Visible = 0;
 DrawImage (&Set_7_);
}
void Set_7_OnDown(){
 Tone1();
#line 2519 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(DEL_HEAT_MAX,1);
 Set_7_.Visible = 0;
 Image252.Visible = 1;
 DrawImage (&Image252);
}

void Set_8_OnDown() {
 Tone1();
#line 2530 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(DEL_DHW_MIN,1);
 Set_8_.Visible = 0;
 Image253.Visible = 1;
 DrawImage (&Image253);
}

void Set_8_OnUp() {
 Set_8_.Visible = 1;
 Image253.Visible = 0;
 DrawImage (&Set_8_);
}

 void Set_9_OnUp() {
 Set_9_.Visible = 1;
 Image256.Visible = 0;
 DrawImage (&Set_9_);
}
void Set_9_OnDown() {
 Tone1();
#line 2552 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(DEL_DHW_MAX,1);
 Set_9_.Visible = 0;
 Image256.Visible = 1;
 DrawImage (&Image256);
}
 void Set_10_OnDown() {
 Tone1();
#line 2562 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(DEL_SOURS_MIN,1);
 Set_10_.Visible = 0;
 Image254.Visible = 1;
 DrawImage (&Image254);
}

void Set_10_OnUp() {
 Set_10_.Visible = 1;
 Image254.Visible = 0;
 DrawImage (&Set_10_);
}
void Set_11_OnDown() {
 Tone1();
#line 2578 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(DEL_SOURS_MAX,1);
 Set_11_.Visible = 0;
 Image255.Visible = 1;
 DrawImage (&Image255);
}
void Set_11_OnUp() {
 Set_11_.Visible = 1;
 Image255.Visible = 0;
 DrawImage (&Set_11_);
}

void Set_12_OnDown() {

}
void Set_12_OnUp() {

}



void Down_19_OnPress() {
 char txt[7];
 Tone3 ();
 Image243.Visible = 1;
 Down_19_.Visible = 0;
 DrawImage(&Image243);
 system_reg[S_HEAT_MAX]--;
 if (system_reg[S_HEAT_MAX] < 0)
 system_reg[S_HEAT_MAX] = 0;
 IntToStr(system_reg[S_HEAT_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_superheat.Caption, txt, 2);
 DrawRoundButton(&Set_max_superheat);
 Delay_ms (100);
}
void Down_19_OnUp() {
 Image243.Visible = 0;
 Down_19_.Visible = 1;
 DrawImage(&Down_19_);
}
void Up_19_OnPress() {
 char txt[7];
 Tone2 ();
 Image236.Visible = 1;
 Up_19_.Visible = 0;
 DrawImage(&Image236);
 system_reg[S_HEAT_MAX]++;
 if (system_reg[S_HEAT_MAX] >99)
 system_reg[S_HEAT_MAX] = 99;
 IntToStr(system_reg[S_HEAT_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_superheat.Caption, txt, 2);
 DrawRoundButton(&Set_max_superheat);
 Delay_ms (100);
}
void Up_19_OnUp() {
 Image236.Visible = 0;
 Up_19_.Visible = 1;
 DrawImage(&Up_19_);
}
void Down_20_OnPress() {
 char txt[7];
 Tone3 ();
 Image244.Visible = 1;
 Down_20_.Visible = 0;
 DrawImage(&Image244);
 system_reg[S_COOL_MIN]--;
 if (system_reg[S_COOL_MIN]<0)
 system_reg[S_COOL_MIN] = 0;
 IntToStr(system_reg[S_COOL_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_subcooling.Caption, txt, 2);
 DrawRoundButton(&Set_min_subcooling);
 Delay_ms (100);
}
void Down_20_OnUp() {
 Image244.Visible = 0;
 Down_20_.Visible = 1;
 DrawImage(&Down_20_);
}
void Up_20_OnPress() {
 char txt[7];
 Tone2 ();
 Image237.Visible = 1;
 Up_20_.Visible = 0;
 DrawImage(&Image237);
 system_reg[S_COOL_MIN]++;
 if (system_reg[S_COOL_MIN]>99)
 system_reg[S_COOL_MIN] = 99;
 IntToStr(system_reg[S_COOL_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_subcooling.Caption, txt, 2);
 DrawRoundButton(&Set_min_subcooling);
 Delay_ms (100);
}
void Up_20_OnUp() {
 Image237.Visible = 0;
 Up_20_.Visible = 1;
 DrawImage(&Up_20_);
}
void Down_21_OnPress() {
 char txt[7];
 Tone2 ();
 Image238.Visible = 1;
 Up_21_.Visible = 0;
 DrawImage(&Image238);
 system_reg[S_COOL_MAX]--;
 if (system_reg[S_COOL_MAX]<0)
 system_reg[S_COOL_MAX] = 0;
 IntToStr(system_reg[S_COOL_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_subcooling.Caption, txt, 2);
 DrawRoundButton(&Set_max_subcooling);
 Delay_ms (100);
}
void Down_21_OnUp() {
 Image245.Visible = 0;
 Down_21_.Visible = 1;
 DrawImage(&Down_21_);
}
void Up_21_OnPress() {
 char txt[7];
 Tone2 ();
 Image238.Visible = 1;
 Up_21_.Visible = 0;
 DrawImage(&Image238);
 system_reg[S_COOL_MAX]++;
 if (system_reg[S_COOL_MAX]>99)
 system_reg[S_COOL_MAX] = 99;
 IntToStr(system_reg[S_COOL_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_subcooling.Caption, txt, 2);
 DrawRoundButton(&Set_max_subcooling);
 Delay_ms (100);
}
void Up_21_OnUp() {
 Image238.Visible = 0;
 Up_21_.Visible = 1;
 DrawImage(&Up_21_);
}

void Down_22_OnPress(){
 char txt[7];
 Image24.Visible = 1;
 Down_22_.Visible = 0;
 DrawImage(&Image24);
 system_reg[HP_MAX]--;
 if (system_reg[HP_MAX]<0)
 system_reg[HP_MAX] = 0;
 IntToStr(system_reg[HP_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_high_pressure.Caption, txt, 2);
 DrawRoundButton(&Set_max_high_pressure);
 Delay_ms (100);
}
void Down_22_OnUp(){
 Image24.Visible = 0;
 Down_22_.Visible = 1;
 DrawImage(&Down_22_);

}
void Up_22_OnPress(){
 char txt[7];
 Image53.Visible = 1;
 Up_22_.Visible = 0;
 DrawImage(&Image53);
 system_reg[HP_MAX]++;
 if (system_reg[HP_MAX]>99)
 system_reg[HP_MAX] = 99;
 IntToStr(system_reg[HP_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_high_pressure.Caption, txt, 2);
 DrawRoundButton(&Set_max_high_pressure);
 Delay_ms (100);
}
void Up_22_OnUp(){
 Image53.Visible = 0;
 Up_22_.Visible = 1;
 DrawImage(&Up_22_);
}
void Down_23_OnPress(){
 char txt[7];
 Image86.Visible = 1;
 Down_23_.Visible = 0;
 DrawImage(&Image86);
 system_reg[HP_MIN]--;
 if (system_reg[HP_MIN]<0)
 system_reg[HP_MIN] = 0;
 IntToStr(system_reg[HP_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_lhigh_pressure.Caption, txt, 2);
 DrawRoundButton(&Set_min_lhigh_pressure);
 Delay_ms (100);
}
void Down_23_OnUp(){
 Image86.Visible = 0;
 Down_23_.Visible = 1;
 DrawImage(&Down_23_);

}
void Up_23_OnPress(){
 char txt[7];
 Image95.Visible = 1;
 Up_23_.Visible = 0;
 DrawImage(&Image95);
 system_reg[HP_MIN]++;
 if (system_reg[HP_MIN]>99)
 system_reg[HP_MIN] = 99;
 IntToStr(system_reg[HP_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_lhigh_pressure.Caption, txt, 2);
 DrawRoundButton(&Set_min_lhigh_pressure);
 Delay_ms (100);
}
void Up_23_OnUp(){
 Image86.Visible = 0;
 Up_23_.Visible = 1;
 DrawImage(&Up_23_);
}

void Set_19_OnUp() {
 Set_19_.Visible = 1;
 Image264.Visible = 0;
 DrawImage (&Set_19_);
}
void void Set_19_OnDown(){
 Tone1();
#line 2808 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(S_HEAT_MAX,1);
 Set_19_.Visible = 0;
 Image264.Visible = 1;
 DrawImage (&Image264);
}
void Set_20_OnDown() {
 Tone1();
#line 2818 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(S_COOL_MIN,1);
 Set_20_.Visible = 0;
 Image265.Visible = 1;
 DrawImage (&Image265);
}
void Set_20_OnUp() {
 Set_20_.Visible = 1;
 Image265.Visible = 0;
 DrawImage (&Set_20_);
}
void Set_21_OnDown() {
 Tone1();
#line 2833 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(S_COOL_MAX,1);
 Set_21_.Visible = 0;
 Image266.Visible = 1;
 DrawImage (&Image266);
}
void Set_21_OnUp() {
 Set_21_.Visible = 1;
 Image266.Visible = 0;
 DrawImage (&Set_21_);
}
void Set_22_OnDown(){
 Tone1();
#line 2848 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(HP_MAX,1);
 Set_22_.Visible = 0;
 Image34.Visible = 1;
 DrawImage (&Image34);
}

void Set_22_OnUp(){
 Tone1();
 Set_22_.Visible = 1;
 Image34.Visible = 0;
 DrawImage (&Set_22_);
}
void Set_23_OnDown(){
 Tone1();
#line 2865 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(HP_MIN,1);
 Set_23_.Visible = 0;
 Image33.Visible = 1;
 DrawImage (&Image33);
}
void Set_23_OnUp(){
 Tone1();
 Set_23_.Visible = 1;
 Image33.Visible = 0;
 DrawImage (&Set_23_);
}


void One_CompressorsOnClick() {
num_page=0;
 if ((unsigned long)One_Compressors.Picture_Name ==  0x00328B0C )
 {
 One_Compressors.Picture_Name =  0x00327390 ;
 Two_Compressors.Visible = 1;
 DrawImage(&Two_Compressors);
 system_reg[NOMB_COMPRESSORS]=2;
 two_compressors_mode= 1 ;
 }
 else {
 One_Compressors.Picture_Name =  0x00328B0C ;
 One_Compressors.Visible = 1;
 DrawImage(&One_Compressors);
 system_reg[NOMB_COMPRESSORS]=1;
 two_compressors_mode= 0 ;
 }
 send_data_packet(NOMB_COMPRESSORS,1);


 Delay_ms (300);
}

void Reversing_ON_HEATOnClick() {
 if ((unsigned long)Reversing_ON_HEAT.Picture_Name ==  0x003296CA )
 {
 Reversing_ON_HEAT.Picture_Name =  0x00327F4E ;
 Reversing_Heat_OFF.Visible = 1;
 DrawImage(&Reversing_Heat_OFF);
 system_reg[REVERS_MOD]=0;

 }
 else {
 Reversing_ON_HEAT.Picture_Name =  0x003296CA ;
 Reversing_ON_HEAT.Visible = 1;
 DrawImage(&Reversing_ON_HEAT);
 system_reg[REVERS_MOD]=1;
 }
 send_data_packet(REVERS_MOD,1);
 Delay_ms (300);
}
void Flow_Source__Sensor_ONOnClick(){

}
void Flow_Source__Heat1_ONOnClick() {

}
void Flow_Source__Heat2_ONOnClick() {

}
void Power_380VOnClick() {
 if ((unsigned long)Power_380V.Picture_Name ==  0x0032A288 )
 {
 Power_380V.Picture_Name =  0x0032689A ;
 Power_220V.Visible = 1;
 DrawImage(&Power_220V);
 system_reg[POWER_380]=0;

 }
 else {
 Power_380V.Picture_Name =  0x0032A288 ;
 Power_380V.Visible = 1;
 DrawImage(&Power_380V);
 system_reg[POWER_380]=1;
 }
 send_data_packet(POWER_380,1);
 Delay_ms (300);



}


void furnance_Mode_onOnClick() {

}

void Furnance_start_temp_DownOnUp() {

}
void Furnance_start_temp_DownOnPress() {

}
void Furnance_HP_OFF_DowmOnUp() {

}
void Furnance_HP_OFF_DowmOnPress() {

}
void Furnance_HP_OFF_UPOnUp() {

}
void Furnance_HP_OFF_UPOnPress() {

}

void Furnance_off_downOnUp() {

}
void Furnance_off_downOnPress() {

}
void Furnance_off_upOnUp() {

}
void Furnance_off_upOnPress() {

}
void Furnance_off_save_onup() {

}
void Furnance_off_save_ondown() {

}
void Furnance_time_downOnUp() {

}
void Furnance_time_downOnPress() {

}
void Furnance_time_upOnUp() {

}
void Furnance_time_upOnPress() {

}
void furnance_time_OFFOnClick() {

}
void Furnance_HP_OFF_save_onup(){
}
void Furnance_start_temp_UPOnUp(){
}
void Furnance_start_temp_UPOnPress(){
 }


void SetIPAddressOnClick() {

}

void SetMaskOnClick() {

}

void SetDNSOnClick() {

}

void LAN_Key_1OnClick() {

}

void LAN_Key_2OnClick() {

}

void LAN_Key_3OnClick() {

}

void LAN_Key_4OnClick() {

}

void LAN_Key_5OnClick() {

}

void LAN_Key_6OnClick() {

}

void LAN_Key_7OnClick() {

}

void LAN_Key_8OnClick() {

}

void LAN_Key_9OnClick() {

}

void LAN_Key_0OnClick() {

}

void LAN_Key_DotOnClick() {

}

void LAN_Key_ClearOnClick() {

}

void LANSetOnClick() {

}
void SetGateWayOnClick(){
}

void Hyst_Heat_downOnUp() {
 Hyst_Heat_down.Visible = 1;
 Image114.Visible = 0;
 DrawImage(&Hyst_Heat_down);
}
void Hyst_Heat_downOnPress() {
char txt[7];
 Tone3 ();
 Hyst_Heat_down.Visible = 0;
 Image114.Visible = 1;
 DrawImage(&Image114);
 system_reg[DIFF_HEAT]--;
 if (system_reg[DIFF_HEAT] <0)
 system_reg[DIFF_HEAT] =0;
 IntToStr(system_reg[DIFF_HEAT], txt);
 Ltrim (txt);
 strncpy(Hysteresis_heating.Caption, txt, 2);
 DrawRoundButton(&Hysteresis_heating);
 Delay_ms (100);
}
void Hyst_Heat_upOnUp() {
 Hyst_Heat_up.Visible = 1;
 Image121.Visible = 0;
 DrawImage(&Hyst_Heat_up);
}
void Hyst_Heat_upOnPress() {
char txt[7];
 Tone3 ();
 Hyst_Heat_up.Visible = 0;
 Image121.Visible = 1;
 DrawImage(&Image121);
 system_reg[DIFF_HEAT]++;
 if (system_reg[DIFF_HEAT] >30)
 system_reg[DIFF_HEAT] =30;
 IntToStr(system_reg[DIFF_HEAT], txt);
 Ltrim (txt);
 strncpy(Hysteresis_heating.Caption, txt, 2);
 DrawRoundButton(&Hysteresis_heating);
 Delay_ms (100);
}
void Hyst_Cool_downOnUp() {
 Hyst_Cool_down.Visible = 1;
 Image115.Visible = 0;
 DrawImage(&Hyst_Cool_down);
}
void Hyst_Cool_downOnPress() {
char txt[7];
 Tone3 ();
 Hyst_Cool_down.Visible = 0;
 Image115.Visible = 1;
 DrawImage(&Image115);
 system_reg[DIFF_COOL]--;
 if (system_reg[DIFF_COOL] <0)
 system_reg[DIFF_COOL] =0;
 IntToStr(system_reg[DIFF_COOL], txt);
 Ltrim (txt);
 strncpy(Hysteresis_cooling.Caption, txt, 2);
 DrawRoundButton(&Hysteresis_cooling);
 Delay_ms (100);
}
void Hyst_Cool_upOnUp() {
 Hyst_Cool_up.Visible = 1;
 Image122.Visible = 0;
 DrawImage(&Hyst_Cool_up);

}
void Hyst_Cool_upOnPress() {
char txt[7];
 Tone3 ();
 Hyst_Cool_up.Visible = 0;
 Image122.Visible = 1;
 DrawImage(&Image122);
 system_reg[DIFF_COOL]++;
 if (system_reg[DIFF_COOL] >30)
 system_reg[DIFF_COOL] =30;
 IntToStr(system_reg[DIFF_COOL], txt);
 Ltrim (txt);
 strncpy(Hysteresis_cooling.Caption, txt, 2);
 DrawRoundButton(&Hysteresis_cooling);
 Delay_ms (100);
}
void Hyst_DHW_downOnUp() {
 Hyst_DHW_down.Visible = 1;
 Image116.Visible = 0;
 DrawImage(&Hyst_DHW_down);
}
void Hyst_DHW_downOnPress() {
char txt[7];
 Tone3 ();
 Hyst_DHW_down.Visible = 0;
 Image116.Visible = 1;
 DrawImage(&Image116);
 system_reg[DIFF_DHW]--;
 if (system_reg[DIFF_DHW] <0)
 system_reg[DIFF_DHW] =0;
 IntToStr(system_reg[DIFF_DHW], txt);
 Ltrim (txt);
 strncpy(Hysteresis_DHW.Caption, txt, 2);
 DrawRoundButton(&Hysteresis_DHW);
 Delay_ms (100);
}
void Hyst_DHW_upOnUp() {
 Hyst_DHW_up.Visible = 1;
 Image123.Visible = 0;
 DrawImage(&Hyst_DHW_up);
}
void Hyst_DHW_upOnPress() {
char txt[7];
 Hyst_DHW_up.Visible = 0;
 Image123.Visible = 1;
 DrawImage(&Image123);
 system_reg[DIFF_DHW]++;
 if (system_reg[DIFF_DHW] >30)
 system_reg[DIFF_DHW] =30;
 IntToStr(system_reg[DIFF_DHW], txt);
 Ltrim (txt);
 strncpy(Hysteresis_DHW.Caption, txt, 2);
 DrawRoundButton(&Hysteresis_DHW);
 Delay_ms (100);
}
void Set_heat_onup(){
 Tone1();
 Image135.Visible = 1;
 Image128.Visible = 0;
 DrawImage (&Image135);
}
void Set_heat_OnDown(){
 Tone1();
#line 3212 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet (DIFF_HEAT,1);
 Image135.Visible = 0;
 Image128.Visible = 1;
 DrawImage (&Image128);
}
void Set_cool_OnUp(){
 Tone1();
 Image138.Visible = 1;
 Image129.Visible = 0;
 DrawImage (&Image138);
}
void Set_cool_OnDown(){
 Tone1();
#line 3228 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet (DIFF_COOL,1);
 Image138.Visible = 0;
 Image129.Visible = 1;
 DrawImage (&Image129);
}
void Set_dhw_OnUp(){
 Tone1();
 Set_DHW_HY.Visible = 1;
 Image130.Visible = 0;
 DrawImage (&Set_DHW_HY);
}
void Set_dhw_OnDown(){
 Tone1();
#line 3244 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet (DIFF_DHW,1);
 Set_DHW_HY.Visible = 0;
 Image130.Visible = 1;
 DrawImage (&Image130);
}


void DEC_EEV2OnPress() {

 }
void INC_EEV2OnPress() {

 }
 void EEV2DownOnUp() {

}

void EEV2DownOnDown() {

}
void EEV2UpOnUp() {

}
void EEV2UpOnDown() {

}
void EEV2_AutoOnClick() {

}

void Mode_ground_onOnClick () {
 if ((unsigned long)Mode_ground_on.Picture_Name ==  0x004214E6 )
 {
 Mode_ground_on.Picture_Name =  0x0041F6E0 ;
 Mode_air_on.Visible= 1;
 DrawImage(&Mode_air_on);
 system_reg[AIRE_TO_WATER]=1;
 ground_heat_pump= 0 ;
 }
 else {
 Mode_ground_on.Picture_Name =  0x004214E6 ;
 Mode_ground_on.Visible= 1;
 DrawImage(&Mode_ground_on);
 system_reg[AIRE_TO_WATER]=0;
 ground_heat_pump= 1 ;
 }
 send_data_packet(AIRE_TO_WATER,1);
 Delay_ms (300);
}






void Down_24_OnPress(){
 char txt[7];
 Image99.Visible = 1;
 Image17.Visible = 0;
 DrawImage(&Image99);
 system_reg[LP_MAX]--;
 if (system_reg[LP_MAX]<0)
 system_reg[LP_MAX] = 0;
 IntToStr(system_reg[LP_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_low_pressure.Caption, txt, 2);
 DrawRoundButton(&Set_max_low_pressure);
 Delay_ms (100);

}
void Down_24_OnUp(){
 Image99.Visible = 0;
 Image17.Visible = 1;
 DrawImage(&Image17);
}
 void Up_24_OnPress(){
 char txt[7];
 Image100.Visible = 1;
 Image12.Visible = 0;
 DrawImage(&Image100);
 system_reg[LP_MAX]++;
 if (system_reg[LP_MAX]>99)
 system_reg[LP_MAX] = 99;
 IntToStr(system_reg[LP_MAX], txt);
 Ltrim (txt);
 strncpy(Set_max_low_pressure.Caption, txt, 2);
 DrawRoundButton(&Set_max_low_pressure);
 Delay_ms (100);

}
void Up_24_OnUp(){
 Image100.Visible = 0;
 Image12.Visible = 1;
 DrawImage(&Image12);
}
void Down_25_OnPress(){
 char txt[7];
 Image280.Visible = 1;
 Image18.Visible = 0;
 DrawImage(&Image280);
 system_reg[LP_MIN]--;
 if (system_reg[LP_MIN]<0)
 system_reg[LP_MIN] = 0;
 IntToStr(system_reg[LP_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_low_pressure.Caption, txt, 3);
 DrawRoundButton(&Set_min_low_pressure);
 Delay_ms (100);

}
void Down_25_OnUp(){
 Image280.Visible = 0;
 Image18.Visible = 1;
 DrawImage(&Image18);

}
void Up_25_OnPress(){
 char txt[15];
 Image281.Visible = 1;
 Image14.Visible = 0;
 DrawImage(&Image281);
 system_reg[LP_MIN]++;
 if (system_reg[LP_MIN]>99)
 system_reg[LP_MIN] = 99;
 IntToStr(system_reg[LP_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_low_pressure.Caption, txt, 3);
 DrawRoundButton(&Set_min_low_pressure);
 Delay_ms (100);
}
void Up_25_OnUp(){
 Image281.Visible = 0;
 Image14.Visible = 1;
 DrawImage(&Image14);
}
void Down_26_OnPress() {

}
void Down_26_OnUp() {

}
void UP_26_OnPress() {

}
void UP_26_OnUp() {

}
void Set_24_OnDown(){
 Tone1();
#line 3396 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(LP_MAX,1);
 Image279.Visible = 0;
 Image29.Visible = 1;
 DrawImage (&Image29);
}
void Set_24_OnUp(){
 Tone1();
 Image279.Visible = 1;
 Image29.Visible = 0;
 DrawImage (&Image279);
}
void Set_25_OnDown(){
Tone1();
#line 3412 "C:/Users/Dumitru/Desktop/dima/alta_2_compressor_display/Controller_Code/mikroC PRO for ARM/Controller_events_code.c"
 send_data_packet(LP_MIN,1);
 Image282.Visible = 0;
 Image22.Visible = 1;
 DrawImage (&Image22);
}
void Set_25_OnUp(){
 Tone1();
 Image282.Visible = 1;
 Image22.Visible = 0;
 DrawImage (&Image282);
}
void Set_26_OnDown() {

}
void Set_26_OnUp() {

}
void Set_phase_check(){

}
void Set_voltage_check(){

}


void Down_13_OnUp() {

}
void Down_13_OnPress() {
}
void Up_13_OnPress() {

}
void Up_13_OnUp() {

}

void Down_14_OnPress() {

}
void Down_14_OnUp() {

}
void Up_14_OnPress() {

}
void Up_14_OnUp() {

}
void Down_15_OnPress() {

}
void Down_15_OnUp() {

}
void Up_15_OnPress() {

}
void Up_15_OnUp() {

}
void Down_16_OnPress() {

}
void Down_16_OnUp() {

}
void Up_16_OnPress() {

}
void Up_16_OnUp() {

}
void Down_17_OnPress() {

}
void Down_17_OnUp() {

}
void Up_17_OnPress() {

}
void Up_17_OnUp() {

}
void Down_18_OnPress() {
 char txt[7];
 Tone3 ();
 Image481.Visible = 1;
 Down_18_.Visible = 0;
 DrawImage(&Image481);
 system_reg[S_HEAT_MIN]--;
 if (system_reg[S_HEAT_MIN] < 0)
 system_reg[S_HEAT_MIN] = 0;
 IntToStr(system_reg[S_HEAT_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_superheat.Caption, txt, 2);
 DrawRoundButton(&Set_min_superheat);
 Delay_ms (100);
}
void Down_18_OnUp() {
 Image481.Visible = 0;
 Down_18_.Visible = 1;
 DrawImage(&Down_18_);
}
void Up_18_OnPress() {
 char txt[7];
 Tone2 ();
 Image477.Visible = 1;
 Up_18_.Visible = 0;
 DrawImage(&Image477);
 system_reg[S_HEAT_MIN]++;
 if (system_reg[S_HEAT_MIN] >99)
 system_reg[S_HEAT_MIN] = 99;
 IntToStr(system_reg[S_HEAT_MIN], txt);
 Ltrim (txt);
 strncpy(Set_min_superheat.Caption, txt, 2);
 DrawRoundButton(&Set_min_superheat);
 Delay_ms (100);
}
void Up_18_OnUp() {
 Image477.Visible = 0;
 Up_18_.Visible = 1;
 DrawImage(&Up_18_);
}
void Set_15_OnUp() {

}
void Set_15_OnDown() {

}
void Set_16_OnUp() {

}
void Set_16_OnDown() {

}
void Set_17_OnUp () {

}
void Set_17_OnDown() {

}
void Set_18_OnUp() {
 Set_18_.Visible = 1;
 Image485.Visible = 0;
 DrawImage (&Set_18_);
}
void Set_18_OnDown() {
 Tone1();

 send_data_packet(S_HEAT_MIN,1);
 Set_18_.Visible = 0;
 Image485.Visible = 1;
 DrawImage (&Image485);
}
void Set_14_OnDown() {

}
void Set_14_OnUp(){
}
void Set_13_OnUp() {

}
void Set_13_OnDown() {

}







void dec_def() {
 char txt[7];
 system_reg[TIME_BETWEEN_DEF]--;
 if (system_reg[TIME_BETWEEN_DEF] < 0)
 system_reg[TIME_BETWEEN_DEF] = 0;
 IntToStr(system_reg[TIME_BETWEEN_DEF], txt);
 Ltrim (txt);
 strncpy(Defrost_on_time.Caption, txt, 2);
 DrawRoundButton(&Defrost_on_time);
 Delay_ms (100);
}

void time_def_dec() {
 char txt[7];
 system_reg[TIME_DEFROST]--;
 if (system_reg[TIME_DEFROST] < 0)
 system_reg[TIME_DEFROST] = 0;
 IntToStr(system_reg[TIME_DEFROST], txt);
 Ltrim (txt);
 strncpy(Defrost_off_time.Caption, txt, 2);
 DrawRoundButton(&Defrost_off_time);
 Delay_ms (100);
}

void temp_on_dec() {
 char txt[7];
 system_reg[TEMP_DEFROST]--;
 if (system_reg[TEMP_DEFROST] < 0)
 system_reg[TEMP_DEFROST] = 0;
 IntToStr(system_reg[TEMP_DEFROST], txt);
 Ltrim (txt);
 strncpy(Defrost_on_temperature.Caption, txt, 2);
 DrawRoundButton(&Defrost_on_temperature);
 Delay_ms (100);
}

void temp_off_dec() {
 char txt[7];
 system_reg[TEMP_STOP_DEFROST]--;
 if (system_reg[TEMP_STOP_DEFROST] < 0)
 system_reg[TEMP_STOP_DEFROST] = 0;
 IntToStr(system_reg[TEMP_STOP_DEFROST], txt);
 Ltrim (txt);
 strncpy(Defrost_off_temperature.Caption, txt, 2);
 DrawRoundButton(&Defrost_off_temperature);
 Delay_ms (100);
}

void hum_dec() {

}

void inc_def() {
 char txt[7];
 system_reg[TIME_BETWEEN_DEF]++;
 if (system_reg[TIME_BETWEEN_DEF] > 99)
 system_reg[TIME_BETWEEN_DEF] = 99;
 IntToStr(system_reg[TIME_BETWEEN_DEF], txt);
 Ltrim (txt);
 strncpy(Defrost_on_time.Caption, txt, 2);
 DrawRoundButton(&Defrost_on_time);
 Delay_ms (100);
}

void time_def_inc() {
 char txt[7];
 system_reg[TIME_DEFROST]++;
 if (system_reg[TIME_DEFROST] >99)
 system_reg[TIME_BETWEEN_DEF] = 99;
 IntToStr(system_reg[TIME_DEFROST], txt);
 Ltrim (txt);
 strncpy(Defrost_off_time.Caption, txt, 2);
 DrawRoundButton(&Defrost_off_time);
 Delay_ms (100);
}

void temp_on_inc() {
 char txt[7];
 system_reg[TEMP_DEFROST]++;
 if (system_reg[TEMP_DEFROST] >99)
 system_reg[TEMP_DEFROST] = 99;
 IntToStr(system_reg[TEMP_DEFROST], txt);
 Ltrim (txt);
 strncpy(Defrost_on_temperature.Caption, txt, 2);
 DrawRoundButton(&Defrost_on_temperature);
 Delay_ms (100);
}

void temp_off_inc() {
 char txt[7];
 system_reg[TEMP_STOP_DEFROST]++;
 if (system_reg[TEMP_STOP_DEFROST] >99)
 system_reg[TEMP_STOP_DEFROST] = 99;
 IntToStr(system_reg[TEMP_STOP_DEFROST], txt);
 Ltrim (txt);
 strncpy(Defrost_off_temperature.Caption, txt, 2);
 DrawRoundButton(&Defrost_off_temperature);
}

void hum_inc() {

}





void hum_set() {

}

void SetUPttimDef() {

 Defrost_set1.Visible = 1;
 Image355.Visible = 0;
 DrawImage (&Defrost_set1);
}

void SetdownttimDef() {
 Defrost_set1.Visible = 0;
 Image355.Visible = 1;
 DrawImage (&Image355);
 send_data_packet(TIME_BETWEEN_DEF,1);
}

void Setdownintdef() {
 Defrost_set2.Visible = 0;
 Image381.Visible = 1;
 DrawImage (&Image381);
 send_data_packet(TIME_DEFROST,1);

}

void Setupintdef() {
 Defrost_set2.Visible = 1;
 Image381.Visible = 0;
 DrawImage (&Defrost_set2);

}

void Setuptempdef() {
 Defrost_set3.Visible = 1;
 Image384.Visible = 0;
 DrawImage (&Defrost_set3);

}

void Setdowntempdef() {
 Defrost_set3.Visible = 0;
 Image384.Visible = 1;
 DrawImage (&Image384);
 send_data_packet(TEMP_DEFROST,1);
}

void temp_off_set() {
 Defrost_set4.Visible = 0;
 Image388.Visible = 1;
 DrawImage (&Image388);
 send_data_packet(TEMP_STOP_DEFROST,1);
}

void temp_on_set() {
 Defrost_set4.Visible = 1;
 Image388.Visible = 0;
 DrawImage (&Defrost_set4);

}
void pushDEF(){
 system_reg[PUSH_DEFROS]=1;
 send_data_packet(PUSH_DEFROS,1);
}
