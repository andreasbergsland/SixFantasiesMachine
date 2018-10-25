
;**************************************************************************
;
;		SIX FANTASIES MACHINE, version 0.50beta
;
;**************************************************************************
;A sound making tool based on Six Fantasies on a Poem by Thomas 
;Campion by Paul Lansky. The tool uses LPC analysis/resynthesis 
;and filtering to emulate the range of vocal transformations that 
;can be heard in Lansky's piece.

;Copyright (C) 2009  Andreas Bergsland

;Correspondence with the author can be made to andreas.bergsland@hf.ntnu.no
;or by mail to: Andreas Bergsland, Institutt for musikk, NTNU, 
;7491 Trondheim, NORWAY
;
;This program is free software: you can redistribute it and/or modify
;it under the terms of the GNU General Public License as published by
;the Free Software Foundation, either version 3 of the License, or
;(at your option) any later version.
;
;This program is distributed in the hope that it will be useful,
;but WITHOUT ANY WARRANTY; without even the implied warranty of
;MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;GNU General Public License for more details.
;
;You should have received a copy of the GNU General Public License
;along with this program.  If not, see <http://www.gnu.org/licenses/>.

;***************************************************************************


<CsoundSynthesizer>

<CsOptions>
-m0 -odac0 -b2048 -B4096 --omacro:Path=/Users/andber/Documents/Prosjekt/SixFantasiesMachine
</CsOptions>

<CsInstruments>

sr        =       14000
kr        =       7000
ksmps     =         2
nchnls    =         2

	zakinit 	19, 1	; Initiate Zak

	chn_a		"MasterOutL", 3
	chn_a		"MasterOutR", 3; Init Master Out channels for writing to file

;**********************************************************************************************************
;		Initiate global variables
;**********************************************************************************************************
#include "inc/global_variables.inc"

;**********************************************************************************************************
;		Set strings for LPC files, phrase text, pitch names, file names and extensions
;**********************************************************************************************************
#include "inc/set_LPC-file_strings.inc"

#include "inc/Set_strings_phrases.inc"

#include "inc/Set_strings_pitches.inc"

#include "inc/Set_strings_WriteFile.inc"




;****************************************************************************************************************
;****************************************************************************************************************
;*******************************	MACROS		*********************************************************
;****************************************************************************************************************
;****************************************************************************************************************

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Tabs/voices: sliders and buttons
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; Group(S): Macro with sliders, buttons and counters for setting the variables for each of the voices in the 
; local area
#include "inc/Tabs_Sliders_and_Buttons.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Voice Controls
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; VOICECONTROLS(N): Macro with buttons and knobs for setting activation, volume, chorus, reverb and panning for 
; the individual voices in the global area.
#include "inc/voice_controls.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Get File Length - set sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; FILELENGTH(L)
#include "inc/filelength.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Set mean pitch
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; SETMEANPITCH(L)
#include "inc/Set_mean_pitch.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Tune
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; TUNE(U)
#include "inc/tune.inc"

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Calculate durations
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; DURATION(B) - Calcluates durations from FTP and SFS sliders. Detects change in durations. Triggers...
; SEGMENTDURATIONS(Y) - ...which sets the values in the text boxes
; TRIGGERDURATIONSET(U) - Make small change in duration values at global init to caclulate durations. (Not necessarry - to be deleted!)
#include "inc/Calculate_durations.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Get pitch names
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; SLIDERINPUT(G)
#include "inc/Get_pitch_names.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Write Preset Values 
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; PRESETWRITE(Q)
#include "inc/write_presets.inc"

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Read Preset Values - Set sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; PRESETREAD(F)
; PRESETREAD_FTP(fp)
#include "inc/read_presets.inc"
#include "inc/read_presets_FTP.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Copy & paste FTP
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; COPYFTP(cf)
; PASTEFTP(pf)
; COPYSFS(cs)
; PASTESFS(ps)
; COPYPchVal(cp)
; PASTEPchVal(pp)
; COPYDiv(cd)
; PASTEDiv(pd)
#include "inc/copy_paste_macros.inc"

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		FilterMacros
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "inc/Filters.inc"			; Defines filters
#include "inc/Filters_read_parameters.inc"	; Read parameters from text file



;****************************************************************************************************************
;****************************************************************************************************************
;*******************************	GLOBAL INSTRUMENTS	*************************************************
;****************************************************************************************************************
;****************************************************************************************************************

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		FL widget instrument for real-time control of parameters
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 	FLpanel         "Six Fantasies Machine",1050,840,50,20 ;***** start of container

iTabWidth	=	1040
iTabHeight	=	490

	FLtabs		iTabWidth, iTabHeight, 5, 5
	
	
	FLgroup		"Sound 1", iTabWidth, iTabHeight, 5, 25, 2
$Group(1)
	FLgroup_end



	FLgroup		"Sound 2", iTabWidth, iTabHeight, 5, 25, 2	
$Group(2)
	FLgroup_end 
	

	FLgroup		"Sound 3", iTabWidth, iTabHeight, 5, 25, 2	
$Group(3)
	FLgroup_end 


	FLgroup		"Sound 4", iTabWidth, iTabHeight, 5, 25, 2	
$Group(4)
	FLgroup_end 
	

	FLgroup		"Sound 5", iTabWidth, iTabHeight, 5, 25, 2	
$Group(5)
	FLgroup_end 
	

	FLgroup		"Sound 6", iTabWidth, iTabHeight, 5, 25, 2	
$Group(6)
	FLgroup_end 
	

	FLgroup		"Sound 7", iTabWidth, iTabHeight, 5, 25, 2	
$Group(7)
	FLgroup_end 
	

	FLgroup		"Sound 8", iTabWidth, iTabHeight, 5, 25, 2	
$Group(8)
	FLgroup_end 
	FLtabs_end

; Include controls for all 8 voices
$VOICECONTROLS(1)
$VOICECONTROLS(2)
$VOICECONTROLS(3)
$VOICECONTROLS(4)
$VOICECONTROLS(5)
$VOICECONTROLS(6)
$VOICECONTROLS(7)
$VOICECONTROLS(8)

iPreX	=	735
iPreY	=	640

; Global controls

;

					;itype, inumx, inumy, iwidth, iheight, ix, 	 iy, 	   iopcode	p4 			 
gkButtons,ihButtons  	FLbutBank  	2, 	4, 	5, 	150, 	120,  iPreX-45, iPreY-170, 0, 92, 0, 0, 2; Trigger instrument 92 with p4=2
;ihButtonsText		FLbox		"Presets", 1, 1, 14, 40, 14, iPreX+10, iPreY-190
gkPresN,ihPresN		FLcount		"User Bank",	 1, 99, 1, 5, 1,  70, 20, iPreX, iPreY,     -1, -1
			FLsetAlign	2, ihPresN
			FLsetVal_i	1, ihPresN

			FLhide		ihButtons 	; Hide button bank, not currently in use

gkPreStor,ihPreStor	FLbutton	"Store",	1, 0, 1,        70, 20, iPreX, iPreY+30,  0 , 91,  0, 0
gkPreRead,ihPreRead	FLbutton	"Recall", 	1, 0, 1,        70, 20, iPreX, iPreY+50,  0 , 92,  0, 0, 1; Trigger instrument 92 with p4=1
gkPreSav,ihPreSav	FLbutton	"SaveSet", 	1, 0, 1,        70, 20, iPreX, iPreY+80,  0 , 101, 0, 0
gkPreOpn,ihPreOpn	FLbutton	"OpenSet", 	1, 0, 1,        70, 20, iPreX, iPreY+100, 0 , 102, 0, 0
			FLhide		ihPreOpn

gkFilterOn, ihFilter	FLbutton	"Filter", 	1, 0, 2,	70, 20, iPreX+185,iPreY-100, 	  0 , 502, 0, .1
	  FLsetVal_i	0, ihFilter
;gkLoop,   ihLoop FLbutton  "Loop",    1,  0,  2, 100, 50,  900, 840, 105, 51, 0, 240; set kp1 to 51 for activating looping trigger control instrument, to 1 for single event trigging
;	  FLsetVal_i   0, ihLoop
gkPlay,   ihPlay FLbutton  "PLAY",       1,  1,  1, 100,  50,   iPreX+175, iPreY+50, 105, 52, 0, 2, 0
	  FLsetVal_i   0, ihPlay

gkWFile, ihWFile FLbutton  "Write File", 1,  1,  1, 100,  50,   iPreX+175, iPreY+110, 105, 52, 0, 2, 1, giFileNum
	  FLsetVal_i   0, ihPlay

gkMaster, ihMaster	FLknob 		"Master volume"	,0, 3, 0, 1, -1, 50, iPreX+195, iPreY-40
	FLsetVal_i	1, ihMaster
	
        FLpanel_end     ;***** end of container

;FLpanel         "Filter 1",100,550,150,550
;FLpanel_end

	FLrun


;****************************************************************************************************************
;****************************************************************************************************************
;*******************************	LOCAL INSTRUMENTS	*************************************************
;****************************************************************************************************************
;****************************************************************************************************************

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		LPC instrument
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	         instr     1


; Set pararmeters
;---------------------------------------
iosdur  =       p3
;print	iosdur
kcps	init	180			; Sets 180Hz as default pitch
iamp	=	p4			; Sets overall amplitude
ierr	=	0.07			; Sets value for noise/buzz desicion. Low value, more noise
ifile	=	p5
gifil5	=	ifile			; Chooses LPC file for reading timepointer values
isource	=	p29			; Sets source, 1 for buzz, 0 for noise
irange  =	p7			; Total stretch/compress in seconds
ipchsrc	=	p28			; Pitch source 1=defined through p-fields, 0 = defined from analysis file
iampsrc	=	1			; Amp source 1= defined through p-fields, 0 = defined from analysis file
ichannel=	p8
itransp	=	p6
iChorus	=	p30
iport	=	p31
iFrqShift=	p32
iNoiseLvl=	p33

;---------------Time points for reading in LPC file--------------
ifilpnt0	=	p9		; file time pointer  O - START TIME FOR READING IN LPC FILE
ifilpnt1	=	p10		; file time pointer  1
ifilpnt2	=	p11		; file time pointer  2
ifilpnt3	=	p12		; file time pointer  3
ifilpnt4	=	p13		; file time pointer  4
ifilpnt5	=	p14		; file time pointer  5 
ifilpnt6	=	p15		; file time pointer  6 - END TIME FOR READING IN LPC FILE

;---------------Stretch factor for each segment designated by time pointer
; 1 = no stretch, 0.5 = compressed to half, 2 = stretched twice the duration
istr1		=	p16		; stretch factor for segment defined by time points 0-1
istr2		=	p17		; stretch factor for segment defined by time points 1-2
istr3		=	p18		; stretch factor for segment defined by time points 2-3
istr4		=	p19		; stretch factor for segment defined by time points 3-4
istr5		=	p20		; stretch factor for segment defined by time points 4-5
istr6		=	p21		; stretch factor for segment defined by time points 5-6

;--------------Pitch points when setting pitch from score--------
ipch0		=	p22	; pitch point 0 - STARTING PITCH WHEN SET FROM SCORE
ipch1		=	p23	; pitch point 1
ipch2		=	p24	; pitch point 2
ipch3		=	p25	; pitch point 3
ipch4		=	p26	; pitch point 4
ipch5		=	p27	; pitch point 5 - ENDING PITCH WHEN SET FROM SCORE


;Read start and end time of segments + transposition, calculate time pointer
istart		=	ifilpnt0
iend		=	ifilpnt6
isegdur		=	iend - istart

;Calculate durations for each segment
idur1		=	(ifilpnt1 - ifilpnt0) * istr1
idur2		=	(ifilpnt2 - ifilpnt1) * istr2	;
idur3		=	(ifilpnt3 - ifilpnt2) * istr3
idur4		=	(ifilpnt4 - ifilpnt3) * istr4
idur5		=	(ifilpnt5 - ifilpnt4) * istr5
idur6		=	(ifilpnt5 - ifilpnt4) * istr6


ktimp   	linseg	istart, idur1 , ifilpnt1, idur2, ifilpnt2, idur3, ifilpnt3, idur4, ifilpnt4, idur5, ifilpnt5, idur6, iend 	; Create timepointer to LPC-read
ktimperr	line	istart, isegdur, iend
ktimp		=	(ktimp<0? ktimperr: ktimp)
kPitchPoints	linseg	ipch0, idur1, ipch0, 0, ipch1, idur2, ipch1, 0, ipch2, idur3,ipch2, 0, ipch3, idur4, ipch3, 0, ipch4, idur5, ipch4, 0, ipch5, idur6, ipch5; Create 5 points for pitch curve in LPC read
kpchp		portk	kPitchPoints, iport, ipch0


;------------Calculate mean pitch value for file segment during first 0.09 sec---------------
		tableiw 0, 2, ifile				; Clear tables at first i-pass
		tableiw 0, 3, ifile
		tableiw 0, 4, ifile				
kn		table	2, ifile				; Reads values from tables for counter,
ksum		table	3, ifile				; sum, and
kmean		table	4, ifile				; mean 
ktim		line	istart, .05, iend			; create a time pointer and 
;printks	"Sum = %6.2f  Mean = %8.3f Num = %5.0f          ", 0.1, ksum, kmean, kn, 0; For debugging
krmsrm, krmsom, kerrm, kcpsm    lpread  ktim, ifile		; read through file in 0.05 sec
kn		= 	(ktim < iend? kn + 1 : kn)		; stop counting when file is read through
ksum		=	(ktim < iend? ksum + kcpsm : ksum) 	; stop summing when file is read through
kmean		=	ksum / kn				; Calculate mean
;printk	.2, kmean
		tablew	ksum,  3, ifile				; Write values for sum, mean and counter to table
		tablew	kmean, 4, ifile
		tablew	kn,    2, ifile

; Read proper LPC analysis file
krmsr, krmso, kerr, kcps    lpread  ktimp, ifile

;-----------Change pitch deviation around mean if irange<0---------------------------
kdiff		=	kcps - kmean				; kdiff = distance from mean
kdiff		=	kdiff * irange				; scale kdiff according to irange
kcps		=	(irange != 1? kmean + kdiff : kcps)	
kpch		=	kcps * ipchsrc + kpchp * (1 - ipchsrc)	; Weighs pitch values from LPC file and from score according to p-field

; Transpose
itransp		=	cpspch((itransp/100)+ 8.24)/cpspch(10.00)
;print		itransp
kpch		=	kpch * itransp


;------------Source signal 1: BUZZ------------------------------------------------------
Source:
; Buzz source
;ierrweigh	=	.03
;kbuzzscal	=	(kerr<ierr? 1: kerr * ierrweigh)	; Scales the buzz according to the error value. If error value is lower than threshold, set to one, else scale down to 3%
abuzz     	buzz      krmso , kpch, int((sr /2)/kpch), 2	; krmso * kbuzzscal, kpch, int((sr/2)/kpch), 2	; Buzz generator, number of partials is defined as Nyquist/pitch to avoid aliasing


;-----------Set global pitch variables------------------------------------------------

gkpitch		=		kpch

if		(ichannel==1)	then
gkpitch1	=	kpch
elseif		(ichannel==2)   then
gkpitch2	=	kpch
elseif		(ichannel==3)   then
gkpitch3	=	kpch
elseif		(ichannel==4)   then
gkpitch4	=	kpch
elseif		(ichannel==5)   then
gkpitch5	=	kpch
elseif		(ichannel==6)   then
gkpitch6	=	kpch
elseif		(ichannel==7)   then
gkpitch7	=	kpch
elseif		(ichannel==8)   then
gkpitch8	=	kpch
endif


;------------Chorus--------------------------------------------------------------------
krand1		randh	kpch * .01, 23
krand2		randh	kpch * .01, 31
krand3		randh	kpch * .01, 37
krand4		randh	kpch * .01, 41

kpch1		=	kpch*0.992 + krand1
kpch2		=	kpch*0.996 + krand2
kpch3		=	kpch*1.004 + krand3
kpch4		=	kpch*1.008 + krand4
;
achorus1	buzz	  krmso, kpch1, int((sr /2)/(kpch1)), 2
achorus2	buzz	  krmso, kpch2, int((sr /2)/(kpch2)), 2
achorus3	buzz	  krmso, kpch3, int((sr /2)/(kpch3)), 2
achorus4	buzz	  krmso, kpch4, int((sr /2)/(kpch3)), 2

achorus		=	  (iChorus * (achorus1+achorus2+achorus3+achorus4)) + abuzz

achorbal	balance	  achorus, abuzz
abuzz		=	  achorbal



;------------Noise source---------------------------------------------------------------
anoise     	rand      krmso

; Buzz / noise desicion
         	if        (kerr > ierr) goto noisy

;-----------Source signal: add bandpassed noise to buzz to increase naturalness----------
buzz:
; Add band passed noise to decrease "buzz" in resynthesized signal
ioverlapfrek	=	4500
alpbuzz		butlp	abuzz, ioverlapfrek				; lowpass buzz
ahpnoise	buthp	anoise, 2200					; bandpass noise
abpnoise	butlp	ahpnoise, 6900
abuzz		=	alpbuzz + abpnoise * .05 + abuzz * .005		; blend lowpassed buzz with bandpassed noise to increase naturalness
asig    	=       (abuzz * isource) + anoise * .4 *(1-isource)	; Weighs buzz source and noise source according to p-field
          		goto      contin

noisy:        
asig     		 =         anoise
          		goto      contin


; -----------LPC Filtering-------------------------------------------------------------------
contin:     

aLPC     	lpfreson   asig, iFrqShift 				; LPC filtering


;-----------Balancing and declick------------------------------------------------------------
;Balancing amplitude with rms signal from LPC file
;armso		=	a(krmso)
iXFadeThrsh	=	.03	; Lower threshold for crossfading between noise and buzz
if        	(kerr > iXFadeThrsh) 	kgoto	attenuate

iref		=	1	; Reference level = 1
katten		=	iref

kgoto		next		; Skip if kerr values below crossfade threshold

attenuate:
katt		=	(kerr-iXFadeThrsh)/(ierr - iXFadeThrsh) * iNoiseLvl
kXFade		=	iref - katt
katten		=	((kerr > ierr)? iNoiseLvl: kXFade)
goto	next




next:
;printks		"ktimp=%5.4f   katten=%5.4f  kerr=%5.4f\n", 1/kr, ktimp, katten, kerr

; Experimental - use only for special purposes
;katten		=	(kerr > ierr? 0.0001 : katten)

abalance	balance  aLPC, anoise


; Scale output, declick 
kdklck		linen	1, .01, p3, .01; Declick envelope
aout		=	abalance * kdklck * katten		; scale




; Balance the LPC signal with the armso except when kerr>ierr, then balance with a scaled down version of armso

;abalance	=	abalance * iamp
;aout		=	abalance


;------------Output---------------------------------------------------
; Voices 1-8 are sent to corresponding zak channels 1-8

if (ichannel ==1) then 		
aout1	=	aout
zawm	aout1, 1

elseif		(ichannel ==2)  then
aout2	=	aout
zawm	aout2, 2

elseif		(ichannel ==3)  then
aout3	=	aout
zawm	aout3, 3

elseif		(ichannel ==4)  then
aout4	=	aout
zawm	aout4, 4

elseif		(ichannel ==5)  then
aout5	=	aout
zawm	aout5, 5

elseif		(ichannel ==6)  then
aout6	=	aout
zawm	aout6, 6

elseif		(ichannel ==7)  then
aout7	=	aout
zawm	aout7, 7

elseif		(ichannel ==8)  then
aout8	=	aout
zawm	aout8, 8

endif	

          endin      


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Turn on Voice 1 On/off button at init
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		instr	20
		FLsetVal_i 1, gihActive1
		endin


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Instruments for setting pitch names and durations in text boxes 
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

; Instr 40 detects slider motion, assigns slider input and performs calculation
		instr	40
;ixP	=	630
;iyP	=	70


; Detects slider motion and triggers setting values for durations text boxes
$DURATION(1)
$DURATION(2)
$DURATION(3)
$DURATION(4)
$DURATION(5)
$DURATION(6)
$DURATION(7)
$DURATION(8)

; Detects slider motion and triggers setting values for pitch names in text boxes
$SLIDERINPUT(1)
$SLIDERINPUT(2)
$SLIDERINPUT(3)
$SLIDERINPUT(4)
$SLIDERINPUT(5)
$SLIDERINPUT(6)
$SLIDERINPUT(7)
$SLIDERINPUT(8)

		endin

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; 		Sets text and color of the FLBoxes
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		instr	41

iSlider		=	p6
SText		strget	p4
;print		p4
STune		strget	p5
;print	p5
SPitch		strcat	SText, STune
FLsetText 	SPitch, p6
iNoteVal	=	p4 - 80000
FLsetColor	255 - (iNoteVal * 13), ((cos(12.5 * iNoteVal/11))+1)* 127, ((sin(12.5 * iNoteVal/11))+1)* 127, p6
turnoff

		endin


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Sets the values of the duration text boxes
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		instr	42

$SEGMENTDURATIONS(1)
$SEGMENTDURATIONS(2)
$SEGMENTDURATIONS(3)
$SEGMENTDURATIONS(4)
$SEGMENTDURATIONS(5)
$SEGMENTDURATIONS(6)
$SEGMENTDURATIONS(7)
$SEGMENTDURATIONS(8)
;prints	"setting segment durations\n"

		endin


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; Instrument to trigger change detection to initiates sliders at starting values
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		instr	43

;prints	"making total duration change to trigger duration setting\n"
$TRIGGERDURATIONSET(1)
$TRIGGERDURATIONSET(2)
$TRIGGERDURATIONSET(3)
$TRIGGERDURATIONSET(4)
$TRIGGERDURATIONSET(5)
$TRIGGERDURATIONSET(6)
$TRIGGERDURATIONSET(7)
$TRIGGERDURATIONSET(8)
		endin



;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Instrument for setting mean pitch
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		instr	45
ivoice		=	p4

if		(ivoice==1)	then
$SETMEANPITCH(1)
elseif		(ivoice==2)	then
$SETMEANPITCH(2)
elseif		(ivoice==3)	then
$SETMEANPITCH(3)
elseif		(ivoice==4)	then
$SETMEANPITCH(4)
elseif		(ivoice==5)	then
$SETMEANPITCH(5)
elseif		(ivoice==6)	then
$SETMEANPITCH(6)
elseif		(ivoice==7)	then
$SETMEANPITCH(7)
elseif		(ivoice==8)	then
$SETMEANPITCH(8)
endif

		endin


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Tuning instrument
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		instr	46

ivoice		=	p4

if 		(ivoice==1)	then
$TUNE(1)
elseif		(ivoice==2)	then
$TUNE(2)
elseif		(ivoice==3)	then
$TUNE(3)
elseif		(ivoice==4)	then
$TUNE(4)
elseif		(ivoice==5)	then
$TUNE(5)
elseif		(ivoice==6)	then
$TUNE(6)
elseif		(ivoice==7)	then
$TUNE(7)
elseif		(ivoice==8)	then
$TUNE(8)
endif
		endin



;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Make tables for presets
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	instr	90

ktrig		init	1
		schedkwhen	ktrig, 0, 1, 100, 0, 0

		endin

		instr	100
gir		ftgen	0, 0, 1024, 2, 0
ifn		=	gir
;		print	ifn
$PRESETWRITE(1)
$PRESETWRITE(2)
$PRESETWRITE(3)
$PRESETWRITE(4)	
$PRESETWRITE(5)
$PRESETWRITE(6)
$PRESETWRITE(7)
$PRESETWRITE(8)
		endin

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Write Presents
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	instr	91

ifn	=	i(gkPresN)+101	
print ifn
$PRESETWRITE(1)
$PRESETWRITE(2)
$PRESETWRITE(3)
$PRESETWRITE(4)	
$PRESETWRITE(5)
$PRESETWRITE(6)
$PRESETWRITE(7)
$PRESETWRITE(8)
	endin

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Read Presets minus FTP's
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	instr	92


ibank	=	p4; ibank=1 => User Bank, ibank=2 => "Factory" presets

if	(ibank==2)  igoto  Factory

ifn	=	i(gkPresN)+101
print	ifn
igoto Contin

Factory:
ifn	=	i(gkButtons) + 201

Contin:
$PRESETREAD(1)
$PRESETREAD(2)
$PRESETREAD(3)
$PRESETREAD(4)
$PRESETREAD(5)
$PRESETREAD(6)
$PRESETREAD(7)
$PRESETREAD(8)

schedule	43, 0, 2
schedule	93, .1, .01, ifn; trigger instr 93 slightly delayed to override default FTP's triggered by instr 71-78

	endin


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Read Presets, FTP's only
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	instr	93
ifn	=	p4
$PRESETREAD_FTP(1)
$PRESETREAD_FTP(2)
$PRESETREAD_FTP(3)
$PRESETREAD_FTP(4)
$PRESETREAD_FTP(5)
$PRESETREAD_FTP(6)
$PRESETREAD_FTP(7)
$PRESETREAD_FTP(8)
	endin


; *****************::::::::::::::::::::::**************************
;		INSTRUMENT 99 - FOR SETTING FACTORY PRESETS (to be deleted)
; *****************::::::::::::::::::::::**************************
;#include "inc/Set_factory_presents_instrument.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Save set
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	instr	101
ktrig	init	1
prints	"Saving Presets File\n"
	ftsave "$Path./presets/Campion_User_bank.txt",  1, 101, 102 , 103 , 104 , 105 , 106 , 107 , 108 , 109 , \
	110 , 111 , 112 , 113 , 114 , 115 , 116 , 117 , 118 , 119 , 120 , 121 , 122 , 123 , 124 , 125 , 126 , 127 , 128 , 129 , \
	130 , 131 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 141 , 142 , 143 , 144 , 145 , 146 , 147 , 148 , 149 , \
	150 , 151 , 152 , 153 , 154 , 155 , 156 , 157 , 158 , 159 , 160 , 161 , 162 , 163 , 164 , 165 , 166 , 167 , 168 , 169 , \
	170 , 171 , 172 , 173 , 174 , 175 , 176 , 177 , 178 , 179 , 180 , 181 , 182 , 183 , 184 , 185 , 186 , 187 , 188 , 189 , \
	190 , 191 , 192 , 193 , 194 , 195 , 196 , 197 , 198 , 199

ktrig	=	0	
	endin

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Load set
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	instr	102
ktrig	init	1
prints	"Loading Presets File\n"
	ftload "$Path./presets/Campion_User_bank.txt", 1, 101, 102 , 103 , 104 , 105 , 106 , 107 , 108 , 109 , \
	110 , 111 , 112 , 113 , 114 , 115 , 116 , 117 , 118 , 119 , 120 , 121 , 122 , 123 , 124 , 125 , 126 , 127 , 128 , 129 , \
	130 , 131 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 141 , 142 , 143 , 144 , 145 , 146 , 147 , 148 , 149 , \
	150 , 151 , 152 , 153 , 154 , 155 , 156 , 157 , 158 , 159 , 160 , 161 , 162 , 163 , 164 , 165 , 166 , 167 , 168 , 169 , \
	170 , 171 , 172 , 173 , 174 , 175 , 176 , 177 , 178 , 179 , 180 , 181 , 182 , 183 , 184 , 185 , 186 , 187 , 188 , 189 , \
	190 , 191 , 192 , 193 , 194 , 195 , 196 , 197 , 198 , 199

ktrig	=	0
	endin

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Load "Factory" set
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	instr	103
ktrig	init	1
prints	"Loading Presets File\n"
	ftload "$Path./presets/Campion_machine_presets.txt", 1, \
	201
;, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, \
;	211, 212, 213, 214, 215, 216, 217, 218, 219, 220

ktrig	=	0
	endin



;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		COPY / PASTE instruments, 201-208, 211-18, 22-228, 231-38, 241-48, 301-08, 311-18, 321-28, 331-38, 341-48
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "inc/Copy_paste_instruments.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Instruments 71-78: Set time pointer values in sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "inc/set_FTPvals_in_sliders.inc"


; *************************Control instrument for loop playing*****************************************
;		instr	   51
;ktrig		=		gkLoop
;idur		=		5
;ilen		=		ftlen (30)
;kphas		phasor		1/idur
;kphas		=		kphas * ilen
;ktrigger	table		kphas, 30
;ktrigger	=		(ktrig == 1? ktrigger:0)
;		schedkwhen	ktrigger, 0, 1, 1, 0,  4
;ktrigger	=		ktrigger + 1
;
;		endin
;

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Play instrument
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

; Triggers instrument 1 with eight instances corresponding to the eight voices
		instr	52

iWrite		=	p4
;print		iWrite

if		(iWrite == 0) goto	OnlyPlay

ktrig1		=	((gkActive1+gkWFile==2)?1 : 0)
ktrig2		=	((gkActive2+gkWFile==2)?1 : 0)
ktrig3		=	((gkActive3+gkWFile==2)?1 : 0)
ktrig4		=	((gkActive4+gkWFile==2)?1 : 0)
ktrig5		=	((gkActive5+gkWFile==2)?1 : 0)
ktrig6		=	((gkActive6+gkWFile==2)?1 : 0)
ktrig7		=	((gkActive7+gkWFile==2)?1 : 0)
ktrig8		=	((gkActive8+gkWFile==2)?1 : 0)
		kgoto	contin

OnlyPlay:
ktrig1		=	((gkActive1+gkPlay==2)?1 : 0)
ktrig2		=	((gkActive2+gkPlay==2)?1 : 0)
ktrig3		=	((gkActive3+gkPlay==2)?1 : 0)
ktrig4		=	((gkActive4+gkPlay==2)?1 : 0)
ktrig5		=	((gkActive5+gkPlay==2)?1 : 0)
ktrig6		=	((gkActive6+gkPlay==2)?1 : 0)
ktrig7		=	((gkActive7+gkPlay==2)?1 : 0)
ktrig8		=	((gkActive8+gkPlay==2)?1 : 0)

contin:


insnum		=	1
imintime	=	0
imaxnum		=	2
;								   p2        p3        p4           p5          	p6            p7	p8	 p9   		p10      p11		p12	    p13		p14   		p15	p16		p17	p18		p19	p20		p21	p22		p23		p24		p25		p26		p27		p28	   p29		p30		p31	   p32		p33		
		schedkwhen	ktrig1, imintime, imaxnum, insnum, gkDelay1, gkdur1 , i(gkVol1), i(gkPhrase1)+1000, i(gkTransp1),i(gkRange1), 1, i(gkFTP100),i(gkFTP101), i(gkFTP102), i(gkFTP103), i(gkFTP104), i(gkFTP105),  i(gkFTP106),i(gkSFS101),i(gkSFS102),i(gkSFS103),i(gkSFS104),i(gkSFS105), i(gkSFS106),i(gkPchVal101),i(gkPchVal102),i(gkPchVal103),i(gkPchVal104),i(gkPchVal105),i(gkPchVal106), i(gkPchSrc1), i(gkNoise1),i(gkChorus1), i(gkPort1), i(gkFrqShift1), i(gkNoiz1);  trigger sound 1
		schedkwhen	ktrig2, imintime, imaxnum, insnum, gkDelay2, gkdur2 , i(gkVol2), i(gkPhrase2)+1000, i(gkTransp2),i(gkRange2), 2, i(gkFTP200),i(gkFTP201), i(gkFTP202), i(gkFTP203), i(gkFTP204), i(gkFTP205),  i(gkFTP206),i(gkSFS201),i(gkSFS202),i(gkSFS203),i(gkSFS204),i(gkSFS205), i(gkSFS206),i(gkPchVal201),i(gkPchVal202),i(gkPchVal203),i(gkPchVal204),i(gkPchVal205),i(gkPchVal206), i(gkPchSrc2), i(gkNoise2),i(gkChorus2), i(gkPort2), i(gkFrqShift2), i(gkNoiz2);  trigger sound 2
		schedkwhen	ktrig3, imintime, imaxnum, insnum, gkDelay3, gkdur3 , i(gkVol3), i(gkPhrase3)+1000, i(gkTransp3),i(gkRange3), 3, i(gkFTP300),i(gkFTP301), i(gkFTP302), i(gkFTP303), i(gkFTP304), i(gkFTP305),  i(gkFTP306),i(gkSFS301),i(gkSFS302),i(gkSFS303),i(gkSFS304),i(gkSFS305), i(gkSFS306),i(gkPchVal301),i(gkPchVal302),i(gkPchVal303),i(gkPchVal304),i(gkPchVal305),i(gkPchVal306), i(gkPchSrc3), i(gkNoise3),i(gkChorus3), i(gkPort3), i(gkFrqShift3), i(gkNoiz3);  trigger sound 3
		schedkwhen	ktrig4, imintime, imaxnum, insnum, gkDelay4, gkdur4 , i(gkVol4), i(gkPhrase4)+1000, i(gkTransp4),i(gkRange4), 4, i(gkFTP400),i(gkFTP401), i(gkFTP402), i(gkFTP403), i(gkFTP404), i(gkFTP405),  i(gkFTP406),i(gkSFS401),i(gkSFS402),i(gkSFS403),i(gkSFS404),i(gkSFS405), i(gkSFS406),i(gkPchVal401),i(gkPchVal402),i(gkPchVal403),i(gkPchVal404),i(gkPchVal405),i(gkPchVal406), i(gkPchSrc4), i(gkNoise4),i(gkChorus4), i(gkPort4), i(gkFrqShift4), i(gkNoiz4);  trigger sound 4
		schedkwhen	ktrig5, imintime, imaxnum, insnum, gkDelay5, gkdur5 , i(gkVol5), i(gkPhrase5)+1000, i(gkTransp5),i(gkRange5), 5, i(gkFTP500),i(gkFTP501), i(gkFTP502), i(gkFTP503), i(gkFTP504), i(gkFTP505),  i(gkFTP506),i(gkSFS501),i(gkSFS502),i(gkSFS503),i(gkSFS504),i(gkSFS505), i(gkSFS506),i(gkPchVal501),i(gkPchVal502),i(gkPchVal503),i(gkPchVal504),i(gkPchVal505),i(gkPchVal506), i(gkPchSrc5), i(gkNoise5),i(gkChorus5), i(gkPort5), i(gkFrqShift5), i(gkNoiz5);  trigger sound 5
		schedkwhen	ktrig6, imintime, imaxnum, insnum, gkDelay6, gkdur6 , i(gkVol6), i(gkPhrase6)+1000, i(gkTransp6),i(gkRange6), 6, i(gkFTP600),i(gkFTP601), i(gkFTP602), i(gkFTP603), i(gkFTP604), i(gkFTP605),  i(gkFTP606),i(gkSFS601),i(gkSFS602),i(gkSFS603),i(gkSFS604),i(gkSFS605), i(gkSFS606),i(gkPchVal601),i(gkPchVal602),i(gkPchVal603),i(gkPchVal604),i(gkPchVal605),i(gkPchVal606), i(gkPchSrc6), i(gkNoise6),i(gkChorus6), i(gkPort6), i(gkFrqShift6), i(gkNoiz6);  trigger sound 6
		schedkwhen	ktrig7, imintime, imaxnum, insnum, gkDelay7, gkdur7 , i(gkVol7), i(gkPhrase7)+1000, i(gkTransp7),i(gkRange7), 7, i(gkFTP700),i(gkFTP701), i(gkFTP702), i(gkFTP703), i(gkFTP704), i(gkFTP705),  i(gkFTP706),i(gkSFS701),i(gkSFS702),i(gkSFS703),i(gkSFS704),i(gkSFS705), i(gkSFS706),i(gkPchVal701),i(gkPchVal702),i(gkPchVal703),i(gkPchVal704),i(gkPchVal705),i(gkPchVal706), i(gkPchSrc7), i(gkNoise7),i(gkChorus7), i(gkPort7), i(gkFrqShift7), i(gkNoiz7);  trigger sound 7
		schedkwhen	ktrig8, imintime, imaxnum, insnum, gkDelay8, gkdur8 , i(gkVol8), i(gkPhrase8)+1000, i(gkTransp8),i(gkRange8), 8, i(gkFTP800),i(gkFTP801), i(gkFTP802), i(gkFTP803), i(gkFTP804), i(gkFTP805),  i(gkFTP806),i(gkSFS801),i(gkSFS802),i(gkSFS803),i(gkSFS804),i(gkSFS805), i(gkSFS806),i(gkPchVal801),i(gkPchVal802),i(gkPchVal803),i(gkPchVal804),i(gkPchVal805),i(gkPchVal806), i(gkPchSrc8), i(gkNoise8),i(gkChorus8), i(gkPort8), i(gkFrqShift8), i(gkNoiz8);  trigger sound 8


kmaxdur		max	gkdur1, gkdur2, gkdur3, gkdur4, gkdur5, gkdur6, gkdur7, gkdur8
kmaxdel		max	gkDelay1,gkDelay2,gkDelay3,gkDelay4,gkDelay5,gkDelay6,gkDelay7,gkDelay8
;printk		1, kmaxdur
ktrig		=	ktrig1 + ktrig2 + ktrig3 + ktrig4 + ktrig5 + ktrig6 + ktrig7 + ktrig8

if		(iWrite == 0) goto	NoWrite
		schedkwhen	ktrig, imintime, imaxnum, 53, 0, (kmaxdur + 10 + kmaxdel)

NoWrite:
if		(gkFilterOn==0) goto 	NoFilter
		schedkwhen	ktrig, imintime, imaxnum, 500, 0, (kmaxdur + 10 + kmaxdel)
NoFilter:


ktrig1		=	0
ktrig2		=	0
ktrig3		=	0
ktrig4		=	0
ktrig5		=	0
ktrig6		=	0
ktrig7		=	0
ktrig8		=	0
gkPlay		=	0
gkWFile		=	0
ktrig		=	0


		endin


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Write to file instruments 53, 54
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		instr	53
; This instrument checks levels, so that recording is turned off when levels approach zero

itime		timek
ktime		timek
ktime		=	ktime - itime

ktrig		init	1

krms		init	1
krmsdel		init	1

aL		zar	10
aR		zar	11
asound		=	aL + aR

kdeclick	linseg	0,.002, 0, .008, 1
asound		=	asound * kdeclick


adelay		delay	asound, .3
krms		rms	(asound + adelay), 30

schedkwhen	ktrig, 1, 1, 54, 0, p3

;printks	"krms=%5.3f \t ktime=%5.3f\n", .05, krms, ktime

if	(krms<0.01 && ktime > 3500) goto	end
goto	continue

end:
;printks  "Ending recording\n", 1/kr	
turnoff2	54, 0, 1
turnoff

continue:

ktrig		=	0

		

		endin



		instr	54

iFileNum	=	giFileNum +50000

aL		zar	10
aR		zar	11

kdeclick	linseg	0,.01, 0, .01, 1
aL		=	aL * kdeclick
aR		=	aR * kdeclick

SNum		strget 		iFileNum
SPathFile	strget		50000
;SExt		strget		50002
SFil		strcat		SPathFile, SNum
SFile		strcat		SFil, ".wav"

fout		SFile, 2, aL, aR

prints	"Writing File \n"
prints	SFile

giFileNum	=	giFileNum + 1

		zacl		10,11

		endin


;***************************************************************************************
;		Print pitch values for all instruments (to be deleted in final version)
;***************************************************************************************

;		instr	80
;
;ktrig		changed	gkpitch
;kdel		delayk	ktrig, .1
;kdel2		delayk	kdel, .1
;ktrig		=	ktrig+kdel
;
;if		(ktrig < 1)	kgoto contin
;printks	"P1=%5.1f P2=%5.1f P3=%5.1f P4=%5.1f P4=%5.1f P5=%5.1f P6=%5.1f P7=%5.1f P8=%5.1f\\n", .05, gkpitch1, gkpitch2, gkpitch3,gkpitch4, gkpitch5, gkpitch6, gkpitch7, gkpitch8
;
;kgoto	end
;contin:
;
;kend		=	ktrig+kdel+kdel2
;if		(kend == 0)	kgoto end
;;printks	"End phras4e\\n", 1
;
;end:
;
;		endin


;***************************************************************************************
;		Filter instrument
;***************************************************************************************
		instr 500

giFilterParams	ftgen	500, 0, 0, -23,	"flt/Filter.txt"
prints	"Filter Instrument On\n"
$FILTERPARAMASSIGN
;prints	"gkFilterGain1_1= %5.5f gkFilterPitch1_1= %5.3f gkDecayTime1_1= %5.3f \n", gkFilterGain1_1, gkFilterPitch1_1, gkDecayTime1_1

$FILTERMACRO(1)
$FILTERMACRO(2)
$FILTERMACRO(3)
$FILTERMACRO(4)
$FILTERMACRO(5)
$FILTERMACRO(6)
$FILTERMACRO(7)
$FILTERMACRO(8)

aout1		=	aFilter1_1 + aFilter1_2 + aFilter1_3 + aFilter1_4 + aFilter1_5 + aFilter1_6 + aFilter1_7 + aFilter1_8 + aFilter1_9
aout2		=	aFilter2_1 + aFilter2_2 + aFilter2_3 + aFilter2_4 + aFilter2_5 + aFilter2_6 + aFilter2_7 + aFilter2_8 + aFilter2_9
aout3		=	aFilter3_1 + aFilter3_2 + aFilter3_3 + aFilter3_4 + aFilter3_5 + aFilter3_6 + aFilter3_7 + aFilter3_8 + aFilter3_9
aout4		=	aFilter4_1 + aFilter4_2 + aFilter4_3 + aFilter4_4 + aFilter4_5 + aFilter4_6 + aFilter4_7 + aFilter4_8 + aFilter4_9
aout5		=	aFilter5_1 + aFilter5_2 + aFilter5_3 + aFilter5_4 + aFilter5_5 + aFilter5_6 + aFilter5_7 + aFilter5_8 + aFilter5_9
aout6		=	aFilter6_1 + aFilter6_2 + aFilter6_3 + aFilter6_4 + aFilter6_5 + aFilter6_6 + aFilter6_7 + aFilter6_8 + aFilter6_9
aout7		=	aFilter7_1 + aFilter7_2 + aFilter7_3 + aFilter7_4 + aFilter7_5 + aFilter7_6 + aFilter7_7 + aFilter7_8 + aFilter7_9
aout8		=	aFilter8_1 + aFilter8_2 + aFilter8_3 + aFilter8_4 + aFilter8_5 + aFilter8_6 + aFilter8_7 + aFilter8_8 + aFilter8_9

itime		timek
ktime		timek
kTime		timeinstk
;printk	0.1, ktime
;printk	0.1, kTime

ktime		=	ktime - itime

krms		init	1
krmsdel		init	1

asound		=	(aout1 + aout2 + aout3 + aout4 + aout5 + aout6 + aout7 + aout8)

kdeclick	linseg	0,.002, 0, .008, 1
asound		=	asound * kdeclick

adelay		delay	asound, .3
krms		rms	(asound + adelay), 30

;if	(kTime == ktime) kgoto end

if	(krms<0.01 && ktime > 3500) kgoto	end
kgoto	continue

end:
printks "Filter Instrument Off\n", 1/kr
turnoff


continue:

zawm		aout1 * gkFilterOn, 12
zawm		aout2 * gkFilterOn, 13
zawm		aout3 * gkFilterOn, 14
zawm		aout4 * gkFilterOn, 15
zawm		aout5 * gkFilterOn, 16
zawm		aout6 * gkFilterOn, 17
zawm		aout7 * gkFilterOn, 18
zawm		aout8 * gkFilterOn, 19


		endin


;***************************************************************************************
;		Instruments for reading parameters for Filter instrument
;***************************************************************************************
		instr 	501
;prints	"Reading Filter Parameters\n"

;ifun	=	500

;$FILTERPARAMASSIGN
;prints	"gkFilterGain1_1= %5.5f gkFilterPitch1_1= %5.3f gkDecayTime1_1= %5.3f \n", gkFilterGain1_1, gkFilterPitch1_1, gkDecayTime1_1

		endin


		instr	502
;prints	"Filter On\n"
;ktrig	init	i(gkFilterOn)
;ifun	=	500
;kind	init	1
;ilen	=	ftlen(ifun)
;
;schedkwhen	ktrig, 0, 1, 503, 0, 0.01
;event	"i", 501, 0, 0, kind		; Trigger instrument for reading one value
;kind	=	kind + 1
;if	kind	> ilen kgoto	end
;kgoto contin
;
;end:
;printks	"Filter Parameters Read \n", 1/kr
;turnoff
;
;contin:
;
;ktrig	=	0

endin


		instr	503
; Read Mix parameters from text file
;prints	"Reading Mix Parameters\n"
;
;gkFilterMix1	tab	1, 500
;gkFilterMix2	tab	2, 500
;gkFilterMix3	tab	3, 500
;gkFilterMix4	tab	4, 500
;gkFilterMix5	tab	5, 500
;gkFilterMix6	tab	6, 500
;gkFilterMix7	tab	7, 500
;gkFilterMix8	tab	8, 500
;printks	"gkFilterMix1 = %5.3f\n", 100/kr, gkFilterMix1


		endin

;***************************************************************************************
;		Zak mixer med romklang
;***************************************************************************************

		instr 1000

adry1		zar	1
adry2		zar	2
adry3		zar	3
adry4		zar	4
adry5		zar	5
adry6		zar	6
adry7		zar	7
adry8		zar	8
adum		=	0

afilt1		zar	12
afilt2		zar	13
afilt3		zar	14
afilt4		zar	15
afilt5		zar	16
afilt6		zar	17
afilt7		zar	18
afilt8		zar	19

aFiltMix1	=	adry1 * (1-gkFilterMix1 * gkFilterOn) + afilt1 * gkFilterMix1  * gkFilterOn
aFiltMix2	=	adry2 * (1-gkFilterMix2 * gkFilterOn) + afilt2 * gkFilterMix2  * gkFilterOn
aFiltMix3	=	adry3 * (1-gkFilterMix3 * gkFilterOn) + afilt3 * gkFilterMix3  * gkFilterOn
aFiltMix4	=	adry4 * (1-gkFilterMix4 * gkFilterOn) + afilt4 * gkFilterMix4  * gkFilterOn
aFiltMix5	=	adry5 * (1-gkFilterMix5 * gkFilterOn) + afilt5 * gkFilterMix5  * gkFilterOn
aFiltMix6	=	adry6 * (1-gkFilterMix6 * gkFilterOn) + afilt6 * gkFilterMix6  * gkFilterOn
aFiltMix7	=	adry7 * (1-gkFilterMix7 * gkFilterOn) + afilt7 * gkFilterMix7  * gkFilterOn
aFiltMix8	=	adry8 * (1-gkFilterMix8 * gkFilterOn) + afilt8 * gkFilterMix8  * gkFilterOn

;printks	"gkFilterGain1_1= %5.5f gkFilterPitch1_1= %5.3f gkDecayTime1_1= %5.3f \n", 1, gkFilterGain1_1, gkFilterPitch1_1, gkDecayTime1_1

awet1, aw	reverbsc  aFiltMix1, adum, .7, 6000
awet2, aw	reverbsc  aFiltMix2, adum, .7, 6000
awet3, aw	reverbsc  aFiltMix3, adum, .7, 6000
awet4, aw	reverbsc  aFiltMix4, adum, .7, 6000
awet5, aw	reverbsc  aFiltMix5, adum, .7, 6000
awet6, aw	reverbsc  aFiltMix6, adum, .7, 6000
awet7, aw	reverbsc  aFiltMix7, adum, .7, 6000
awet8, aw	reverbsc  aFiltMix8, adum, .7, 6000


amix1		=	(aFiltMix1 * (1-gkRevMix1) + awet1 * gkRevMix1) * gkVol1 
amix2		=	(aFiltMix2 * (1-gkRevMix2) + awet2 * gkRevMix2) * gkVol2
amix3		=	(aFiltMix3 * (1-gkRevMix3) + awet3 * gkRevMix3) * gkVol3
amix4		=	(aFiltMix4 * (1-gkRevMix4) + awet4 * gkRevMix4) * gkVol4
amix5		=	(aFiltMix5 * (1-gkRevMix5) + awet5 * gkRevMix5) * gkVol5 
amix6		=	(aFiltMix6 * (1-gkRevMix6) + awet6 * gkRevMix6) * gkVol6
amix7		=	(aFiltMix7 * (1-gkRevMix7) + awet7 * gkRevMix7) * gkVol7
amix8		=	(aFiltMix8 * (1-gkRevMix8) + awet8 * gkRevMix8) * gkVol8


aL1, aR1	pan2	amix1, gkPan1, 1
aL2, aR2	pan2	amix2, gkPan2, 1
aL3, aR3	pan2	amix3, gkPan3, 1
aL4, aR4	pan2	amix4, gkPan4, 1
aL5, aR5	pan2	amix5, gkPan5, 1
aL6, aR6	pan2	amix6, gkPan6, 1
aL7, aR7	pan2	amix7, gkPan7, 1
aL8, aR8	pan2	amix8, gkPan8, 1		
;aL1	=	sqrt(gkPan1)    * amix1
;aR1	=	sqrt(1-gkPan1) * amix1
;aL2	=	sqrt(gkPan2)    * amix2
;aR2	=	sqrt(1-gkPan2) * amix2
;aL3	=	sqrt(gkPan3)    * amix3
;aR3	=	sqrt(1-gkPan3) * amix3
;aL4	=	sqrt(gkPan4)    * amix4
;aR4	=	sqrt(1-gkPan4) * amix4
;aL5	=	sqrt(gkPan5)    * amix5
;aR5	=	sqrt(1-gkPan5) * amix5
;aL6	=	sqrt(gkPan6)    * amix6
;aR6	=	sqrt(1-gkPan6) * amix6
;aL7	=	sqrt(gkPan7)    * amix7
;aR7	=	sqrt(1-gkPan7) * amix7
;aL8	=	sqrt(gkPan8)    * amix8
;aR8	=	sqrt(1-gkPan8) * amix8

;printks	"Amp2 %5.3f \\t", .2, kamp1, kamp2,kamp3,kamp4
;printks	"Pan1 %5.3f %5.3f %5.3f %5.3f \\n", .2, gkVol5, gkVol6,gkVol7,gkVol8

aoutL		=	(aL1 + aL2 + aL3 + aL4 + aL5 + aL6 + aL7 + aL8) * gkMaster; + accompL
aoutR		=	(aR1 + aR2 + aR3 + aR4 + aR5 + aR6 + aR7 + aR8) * gkMaster; + accompR

		zawm	aoutL, 10
		zawm	aoutR, 11
		outs	aoutL, aoutR

		
;chnmix		aoutL, "MasterOutL"
;chnmix		aoutR, "MasterOutR"
;chnclear	"MasterOutL"
;chnclear	"MasterOutR"

		zacl	1, 9
		zacl	12,19
	
endin


</CsInstruments>

<CsScore>
f2 0 16384 10 1	

f4 0 4 -2 0 0			; tables for temporary storing mean pitch value


f201 0 1024 2 0 		; make tables for the Factory Presets
f202 0 1024 2 0 
f203 0 1024 2 0 
f204 0 1024 2 0 
f205 0 1024 2 0 
f206 0 1024 2 0 
f207 0 1024 2 0 
f208 0 1024 2 0 
f209 0 1024 2 0 
f210 0 1024 2 0 
f211 0 1024 2 0 
f212 0 1024 2 0 
f213 0 1024 2 0 
f214 0 1024 2 0 
f215 0 1024 2 0 
f216 0 1024 2 0 
f217 0 1024 2 0 
f218 0 1024 2 0 
f219 0 1024 2 0 
f220 0 1024 2 0

;f500 0 0 -23	"flt/Filter.txt"

; ----------tables for default start and end values and mean pitch values
;           st	end	kn	ksum	kmean
f1001 0 8 -2 0 	1.61	0	0	210.56	0 0 0; Rose cheeked Lawra	
f1002 0 8 -2 0 	0.85	0	0	184.14	0 0 0; Come
f1003 0 8 -2 0 	2.83	0	0	225.19	0 0 0; Sing thy smoothly with thy bewties
f1004 0 8 -2 0 	1.19	0	0	221.7	0 0 0; Silent music
f1005 0 8 -2 0 	0.79	0	0	211.84	0 0 0; Either other
f1006 0 8 -2 0 	1.19	0	0	201.66	0 0 0; Sweetly gracing
f1007 0 8 -2 0 	1.82	0	0	229.45	0 0 0; Lovely formes do flow
f1008 0 8 -2 0 	2.95	0	0	203.67	0 0 0; From consent devinely framed
f1009 0 8 -2 0 	1.19	0	0	232.33	0 0 0; Heaven is music
f1010 0 8 -2 0 	1.38	0	0	204.70	0 0 0; And thy bewties birth
f1011 0 8 -2 0 	0.89	0	0	194.67	0 0 0; Is heavenly
f1012 0 8 -2 0 	2.33	0	0	173.62	0 0 0; These dull notes we sing  - replaced with f112 because of bug
f1013 0 8 -2 0 	2.69	0	0	190.09	0 0 0; Discord needs for helps to grace them
f1014 0 8 -2 0 	2.17	0	0	197.52	0 0 0; Only bewty purely loving
f1015 0 8 -2 0 	1.38	0	0	182.31	0 0 0; Knows no discord
f1016 0 8 -2 0 	0.77	0	0	179.66	0 0 0; But still
f1017 0 8 -2 0 	1.11	0	0	191.77	0 0 0; Moves delight
f1018 0 8 -2 0 	3.60	0	0	178.15	0 0 0; LIke clear springs renued by flowing
f1019 0 8 -2 0 	1.68	0	0	200.51	0 0 0; Ever perfect
f1020 0 8 -2 0 	1.58	0	0	195.4	0 0 0; Ever in themselves
f1021 0 8 -2 0 	0.76	0	0	165.38	0 0 0; Eternall
f1022 0 8 -2 0 	2.33	0	0	212.74	0 0 0; These dull notes we sing


f30 0 8192 -7 1 1 0 8191 0

f40 0 16384 -2 0 

;----------------------------------------------------------------------------------------------------
;		EVENTS
;----------------------------------------------------------------------------------------------------

; Turn on voice 1 at init
i20 0 0 

; instrument for detecting motion in the duration variables (dependant on FTP and SFS slider motion), always on
i40 0 7200

; instrument that make duration gkdur1 change so that sliders are set at initvalues for durations
i43 1 .2

; Activate instrument 90 long enough to make 100 tables for the User-bank
i90 0 .035

; Write presets
i91 .5 0 
; 					Pitch source 0=defined through p-fields, 1 = defined from LPC file, -1 =defined through analysis files

; Load Factory Presets
i103 .2 0 

; Load User Presets
i102 .22 0

; Filters (test)
;i500 0.1 3600
;i502 0	.1	; read parameters from file
;i503 .01 .01	; read Mix parameters

; Reverb instrument, always on
i1000 0 7200
</CsScore>

</CsoundSynthesizer>

