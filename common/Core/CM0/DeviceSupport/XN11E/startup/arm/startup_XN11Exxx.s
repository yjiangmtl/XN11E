;/*****************************************************************************
; * @file:    startup_XN11Exxx.s
; * @description: CMSIS Cortex-M0 Core Device Startup File 
; *           for the Xinova XN11E Device Series 
; * @version: V1.0
; * @date:    21 Jan. 2015
; *-----------------------------------------------------------------------------
;
;/*****************************************************************************/
;/* Startup.s: Startup file for ARM Cortex-M0 Device Family                   */
;/*****************************************************************************/


;// <h> Stack Configuration
;//   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Heap_Size       EQU     0x00000100

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler
                ; External Interrupts
                DCD     WAKEUP_IRQHandler         ; 16+ 0: Wakeup 0	 Handler
                DCD     PMWFAULT_IRQHandler         ; 16+ 1: PWM Fault interrupt	Handler
                DCD     TWS_IRQHandler    ; 16+ 2: TWS	interrupt	Handler
		DCD       CT16B0_IRQHandler               ; 16+3, 16-bit Timer0 Interrupt Handler 
		DCD       CT16B1_IRQHandler               ; 16+4, 16-bit Timer1 Interrupt Handler
		DCD       CT16B2_IRQHandler               ; 16+5,  16-bit Timer2 Interrupt Handler
		DCD       CT16B3_IRQHandler               ; 16+6,  16-bit Timer3 Interrupt Handler
                DCD      UART0_IRQHandler                    ; 16+7,  UART0 Interrupt Handler   
		DCD       UART1_IRQHandler                    ; 16+8,  UART1 Interrupt Handler    
		DCD       ADC_IRQHandler                      ; 16+9,  A/D Converter Interrupt Handler
		DCD      WDT_IRQHandler                      ; 16+10,  Watchdog timer Interrupt Handler   
		DCD       BOD_IRQHandler                      ; 16+11, Brown Out Detect(BOD) Interrupt Handler
		DCD       GPIO0_IRQHandler                    ; 16+12, External Interrupt 0 Interrupt Handler
		DCD       GPIO1_IRQHandler                    ; 16+13, External Interrupt 1 Interrupt Handler
		DCD       GPIO2_IRQHandler                    ; 16+14, External Interrupt 2 Interrupt Handler
		DCD       RTC_IRQHandler                      ; 16+15, RTC Interrupt Handler           
		DCD       SPI_IRQHandler                      ; 16+16, SSP Interrupt Handler           
		DCD       PWMEVENT_IRQHandler                ; 16+17, PWM Timer Interrupt Handler 
		DCD     CAPTOUCH_IRQHandler         ; 16+18: Cap touch sense Handler                
                DCD     0          ; 16+19: : Reserved
                DCD     0           ; 16+20: Reserved              
                DCD     0           ; 16+21: Reserved
                DCD     0            ; 16+22: Reserved                
                DCD     0            ; 16+23: Reserved
                DCD     0						  ; 16+24: Reserved
                DCD     0          ; 16+25: Reserved
                DCD     0          ; 16+26: Reserved
                DCD     0          ; 16+27: Reserved
                DCD     0						  ; 16+28: Reserved
                DCD     0            ; 16+29: Reserved
                DCD     0            ; 16+30: Reserved
                DCD     0            ; 16+31: Reserved   

__Vectors_End

__Vectors_Size         EQU     __Vectors_End - __Vectors
                AREA    |.text|, CODE, READONLY
 
; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                LDR     R0, =__main
                BX      R0
                ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler    PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
               EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP
Default_Handler PROC
                EXPORT  NMI_Handler               [WEAK]
                EXPORT  WAKEUP_IRQHandler         [WEAK]
		EXPORT  PMWFAULT_IRQHandler           [WEAK]
		EXPORT  TWS_IRQHandler           [WEAK]
                EXPORT  CT16B0_IRQHandler      [WEAK]
                EXPORT  CT16B1_IRQHandler      [WEAK]
                EXPORT  CT16B2_IRQHandler      [WEAK]
                EXPORT  CT16B3_IRQHandler      [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
		EXPORT  ADC_IRQHandler           [WEAK]
                EXPORT  WDT_IRQHandler            [WEAK]
                EXPORT  BOD_IRQHandler            [WEAK]
                EXPORT	GPIO0_IRQHandler          [WEAK]
                EXPORT	GPIO1_IRQHandler          [WEAK]
                EXPORT  GPIO2_IRQHandler          [WEAK]
                EXPORT  RTC_IRQHandler            [WEAK]
		EXPORT  SPI_IRQHandler            [WEAK]
                EXPORT  PWMEVENT_IRQHandler            [WEAK]
                EXPORT  CAPTOUCH_IRQHandler            [WEAK]


WAKEUP_IRQHandler
PMWFAULT_IRQHandler 
TWS_IRQHandler
CT16B0_IRQHandler
CT16B1_IRQHandler
CT16B2_IRQHandler
CT16B3_IRQHandler
UART0_IRQHandler
UART1_IRQHandler
ADC_IRQHandler
WDT_IRQHandler
BOD_IRQHandler
GPIO0_IRQHandler  
GPIO1_IRQHandler 
GPIO2_IRQHandler
RTC_IRQHandler
SPI_IRQHandler
PWMEVENT_IRQHandler
CAPTOUCH_IRQHandler


				B   .   
				ENDP

                ALIGN
  
; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

                END

