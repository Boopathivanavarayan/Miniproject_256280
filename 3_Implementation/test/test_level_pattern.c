#include"test_game.h"
//Default controls
int Level = 1;
char up_left = 'q',up_down='w',up_up='e',up_right='r';
char down_left = 'h',down_down='j',down_up='k',down_right='l';

//Game patterns

//Easy

char pattern1[7][25]={
    {"-------------------------"},
    {"|------------------------"},
    {"#######------------------"},
    {"|------####--------------"},
    {"-----------#######-------"},
    {"------------------#######"},
    {"-------------------------"}
};
//medium 

char pattern2[20][50]={
    {"--------------------------------------------------"},
    {"|-------------------------------------------------"},
    {"#-------------------------------------------------"},
    {"|#------------------------------------------------"},
    {"--#-----------------------------------------------"},
    {"---###--------------------------------------------"},
    {"-----#--------------------------------------------"},
    {"------#-------------------------------------------"},
    {"-------#------------------------------------------"},
    {"--------####------###-----------------------------"},
    {"------------#--###---#----------------------------"},
    {"-------------##-------##--------------------------"},
    {"------------------------#--------#----------------"},
    {"-------------------------###----#-####--#---------"},
    {"----------------------------#--#------##-##-----##"},
    {"-----------------------------##------------#--##--"},
    {"--------------------------------------------##----"},
    {"--------------------------------------------------"},
    {"--------------------------------------------------"},
    {"--------------------------------------------------"}
};
//Hard

char pattern3[20][100]={
    {"----------------------------------------------------------------------------------------------------"},
    {"|---------------------------------------------------------------------------------------------------"},
    {"#---------------------------------------------------------------------------------------------------"},
    {"|#--------------------------------------------------------------------------------------------------"},
    {"--#-------------------------------------------------------------------------------------------------"},
    {"---###----------------------------------------------------------------------------------------------"},
    {"-----#---------------------------------------------------------###----------------------------------"},
    {"------#-----------------------------------------------------###---#---------------------------------"},
    {"-------#-------------------------------------------------###-------#--------------------------------"},
    {"--------####------###----------------------------------##-----------##-##---------------------------"},
    {"------------#--###---#--------------------------------#---------------#--#--------------------------"},
    {"-------------##-------##-----------------------------#--------------------#-------------------------"},
    {"------------------------#--------#-----------------##----------------------##------#----------------"},
    {"-------------------------###----#-####--#---------#--------------------------#----#-#---------------"},
    {"----------------------------#--#------##-##-----##----------------------------##-#---#--------#-----"},
    {"-----------------------------##------------#--##--------------------------------#-----#------#-#----"},
    {"--------------------------------------------##-----------------------------------------#---##---##--"},
    {"----------------------------------------------------------------------------------------###-------##"},
    {"----------------------------------------------------------------------------------------------------"},
    {"----------------------------------------------------------------------------------------------------"}
};

