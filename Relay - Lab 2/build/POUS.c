void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->SENSOR_IR,0,retain)
  __INIT_VAR(data__->SWITCH,0,retain)
  __INIT_VAR(data__->POS_X,500,retain)
  __INIT_VAR(data__->POS_Y,500,retain)
  __INIT_VAR(data__->LED,0,retain)
  __INIT_VAR(data__->RELE,0,retain)
  __INIT_VAR(data__->BOCINA,0,retain)
  SR_init__(&data__->SR0,retain);
  R_TRIG_init__(&data__->R_TRIG0,retain);
  TP_init__(&data__->TP0,retain);
  TOF_init__(&data__->TOF0,retain);
  SR_init__(&data__->SR1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->ZM_X_LEFT,400,retain)
  __INIT_VAR(data__->ZM_X_RIGHT,600,retain)
  __INIT_VAR(data__->ZM_Y_TOP,600,retain)
  __INIT_VAR(data__->ZM_Y_BOTTOM,400,retain)
  TP_init__(&data__->TP1,retain);
  TOF_init__(&data__->TOF1,retain);
  __INIT_VAR(data__->_TMP_NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND34_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND6_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND8_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT18_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT3_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND4_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE45_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE44_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR48_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND11_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR22_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_NOT2_OUT,,!(__GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->R_TRIG0.,CLK,,(__GET_VAR(data__->SENSOR_IR,) && __GET_VAR(data__->SENSOR_IR,)));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,_TMP_AND34_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT2_OUT,),
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,)));
  __SET_VAR(data__->,_TMP_AND1_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (BOOL)__GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->_TMP_AND34_OUT,));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->_TMP_AND1_OUT,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,RELE,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->,_TMP_NOT7_OUT,,!(__GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->,_TMP_AND10_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR0.Q1,),
    (BOOL)__GET_VAR(data__->SWITCH,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->_TMP_AND10_OUT,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,_TMP_AND6_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT7_OUT,),
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,)));
  __SET_VAR(data__->,_TMP_AND8_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,),
    (BOOL)__GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->_TMP_AND6_OUT,));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->_TMP_AND8_OUT,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,_TMP_NOT18_OUT,,!(__GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->,_TMP_AND17_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR0.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_NOT18_OUT,)));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 2500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,_TMP_NOT3_OUT,,!(__GET_VAR(data__->TOF0.Q,)));
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->_TMP_NOT3_OUT,));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,_TMP_AND4_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND17_OUT,),
    (BOOL)__GET_VAR(data__->TP0.Q,)));
  __SET_VAR(data__->,_TMP_GE45_OUT,,GE__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->POS_X,),
    (UINT)__GET_VAR(data__->ZM_X_RIGHT,)));
  __SET_VAR(data__->,_TMP_LE44_OUT,,LE__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->POS_X,),
    (UINT)__GET_VAR(data__->ZM_X_LEFT,)));
  __SET_VAR(data__->,_TMP_GE15_OUT,,GE__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->POS_Y,),
    (UINT)__GET_VAR(data__->ZM_Y_TOP,)));
  __SET_VAR(data__->,_TMP_LE13_OUT,,LE__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->POS_Y,),
    (UINT)__GET_VAR(data__->ZM_Y_BOTTOM,)));
  __SET_VAR(data__->,_TMP_OR48_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)4,
    (BOOL)__GET_VAR(data__->_TMP_GE45_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LE44_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GE15_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LE13_OUT,)));
  __SET_VAR(data__->,_TMP_AND11_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR1.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_OR48_OUT,)));
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_VAR(data__->,_TMP_NOT25_OUT,,!(__GET_VAR(data__->TOF1.Q,)));
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->_TMP_NOT25_OUT,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,_TMP_AND23_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND11_OUT,),
    (BOOL)__GET_VAR(data__->TP1.Q,)));
  __SET_VAR(data__->,_TMP_OR22_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND4_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND23_OUT,)));
  __SET_VAR(data__->,BOCINA,,__GET_VAR(data__->_TMP_OR22_OUT,));
  __SET_VAR(data__->,LED,,__GET_VAR(data__->SR1.Q1,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





