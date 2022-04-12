  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AvionicStateFlow_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_P.RepeatingSequenceStair2_OutValu
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_P.RepeatingSequenceStair1_OutValu
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 11;
	
	  ;% AvionicStateFlow_P.RepeatingSequenceStair_OutValue
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_P.LimitedCounter_uplimit
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_P.LimitedCounter_uplimit_e
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_P.LimitedCounter_uplimit_d
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_P.Barometer_SampleTime
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_P.I2CMasterRead_SampleTime
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_P.Constant_Value
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AvionicStateFlow_P.MPU9250_SampleTime
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AvionicStateFlow_P.Outport_Y0
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AvionicStateFlow_P.Constant_Value_o
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AvionicStateFlow_P.Constant3_Value
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AvionicStateFlow_P.RateTransition3_InitialConditio
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AvionicStateFlow_P.Constant_Value_ov
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AvionicStateFlow_P.Constant1_Value
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 9;
	
	  ;% AvionicStateFlow_P.RateTransition1_InitialConditio
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 10;
	
	  ;% AvionicStateFlow_P.RateTransition2_InitialConditio
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 11;
	
	  ;% AvionicStateFlow_P.RateTransition3_InitialCondit_h
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 12;
	
	  ;% AvionicStateFlow_P.Constant4_Value
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 13;
	
	  ;% AvionicStateFlow_P.TSamp_WtEt
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_P.Gain_Gain
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_P.Constant_Value_c
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_P.Constant_Value_ou
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AvionicStateFlow_P.ManualSwitch_CurrentSetting
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AvionicStateFlow_P.Output_InitialCondition
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AvionicStateFlow_P.FixPtConstant_Value
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AvionicStateFlow_P.Output_InitialCondition_c
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AvionicStateFlow_P.FixPtConstant_Value_c
	  section.data(8).logicalSrcIdx = 30;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AvionicStateFlow_P.Output_InitialCondition_i
	  section.data(9).logicalSrcIdx = 31;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AvionicStateFlow_P.FixPtConstant_Value_n
	  section.data(10).logicalSrcIdx = 32;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AvionicStateFlow_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_B.ManualSwitch
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_B.RateTransition3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_B.RateTransition1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AvionicStateFlow_B.RateTransition1_l
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AvionicStateFlow_B.RateTransition2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AvionicStateFlow_B.RateTransition3_l
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AvionicStateFlow_B.Sum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AvionicStateFlow_B.Input
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AvionicStateFlow_B.MPU9250_o1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AvionicStateFlow_B.MPU9250_o2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% AvionicStateFlow_B.x
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% AvionicStateFlow_B.acc
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% AvionicStateFlow_B.h_AGL
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 20;
	
	  ;% AvionicStateFlow_B.rho
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 21;
	
	  ;% AvionicStateFlow_B.Barometer
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AvionicStateFlow_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.obj_f
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.obj_i
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.obj_k
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_DW.obj_n
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.obj_d
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.UD_DSTATE
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_DW.RateTransition3_Buffer0
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_DW.RateTransition1_Buffer0
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AvionicStateFlow_DW.RateTransition2_Buffer0
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AvionicStateFlow_DW.RateTransition3_Buffer0_i
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AvionicStateFlow_DW.RateTransition_Buffer
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AvionicStateFlow_DW.x_est_p
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AvionicStateFlow_DW.P
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 2;
	
	  ;% AvionicStateFlow_DW.Scope2_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 4;
	
	  ;% AvionicStateFlow_DW.Scope_PWORK_c.LoggedData
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 6;
	
	  ;% AvionicStateFlow_DW.Scope1_PWORK_e.LoggedData
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.is_c3_AvionicStateFlow
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_DW.Output_DSTATE_a
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_DW.Output_DSTATE_c
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AvionicStateFlow_DW.IfActionSubsystem4_SubsysRanBC
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AvionicStateFlow_DW.IfActionSubsystem3_SubsysRanBC
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AvionicStateFlow_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AvionicStateFlow_DW.IfActionSubsystem_SubsysRanBC
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AvionicStateFlow_DW.is_active_c3_AvionicStateFlow
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 329668525;
  targMap.checksum1 = 3846635709;
  targMap.checksum2 = 655668396;
  targMap.checksum3 = 770457555;

