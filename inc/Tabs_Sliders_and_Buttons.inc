
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

;"Tabs_Sliders_and_Buttons.inc"



#define Group(S)
#
gixF	=	10
giyF	=	70
ixP	=	630
iyP	=	90


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Copy and Paste Buttons
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

gkCopyFTP$S , gihCopyFTP$S	FLbutton	"Copy"  	,1, 0, 1, 45, 30, gixF + 90 , iyP - 57, 0, 20$S , 0, 2
				FLsetTextSize 12, gihCopyFTP$S

gkCopySFS$S , gihCopySFS$S	FLbutton	"Copy"  	,1, 0, 1, 45, 30, gixF + 380 , iyP - 40, 0, 21$S , 0, 2
				FLsetTextSize 12, gihCopySFS$S

gkCopyPch$S , gihCopyPch$S	FLbutton	"Copy"  	,1, 0, 1, 45, 30, gixF + 675 , iyP - 40, 0, 22$S , 0, 2
				FLsetTextSize 12, gihCopyPch$S

gkCopyDiv$S , gihCopyDiv$S	FLbutton	"Copy"  	,1, 0, 1, 45, 30, gixF + 960 , iyP + 300, 0, 23$S , 0, 2
				FLsetTextSize 12, gihCopyDiv$S

gkCopyAll$S, gihCopyAll$S	FLbutton	"Copy  all"  	,1, 0, 1, 55, 40, gixF + 370 , iyP + 290, 0, 24$S , 0, 2
				FLsetTextSize 14, gihCopyAll$S

gkPasteFTP$S , gihPasteFTP$S	FLbutton	"Paste"  	,1, 0, 1, 45, 30, gixF + 170 , iyP - 57, 0, 30$S , 0, 2
				FLsetTextSize 12, gihPasteFTP$S

gkPasteSFS$S , gihPasteSFS$S	FLbutton	"Paste"  	,1, 0, 1, 45, 30, gixF + 460 , iyP - 40, 0, 31$S , 0, 2
				FLsetTextSize 12, gihPasteSFS$S

gkPastePch$S, gihPastePch$S	FLbutton	"Paste"  	,1, 0, 1, 45, 30, gixF + 755 , iyP - 40, 0, 32$S , 0, 2
				FLsetTextSize 12, gihPastePch$S

gkPasteDiv$S , gihPasteDiv$S	FLbutton	"Paste"  	,1, 0, 1, 45, 30, gixF + 960 , iyP + 340, 0, 33$S , 0, 2
				FLsetTextSize 12, gihPasteDiv$S

gkPasteAll$S , gihPasteAll$S	FLbutton	"Paste all"  	,1, 0, 1, 55, 40, gixF + 470 , iyP + 290, 0, 34$S , 0, 2
				FLsetTextSize 14, gihPasteAll$S


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Set Default durations
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
gkDefaultDur$S , gihDefaultDur$S	FLbutton	"Default"  	,1, 0, 1, 45, 30, gixF + 280 , iyP - 40, 0, 35$S , 0, 2
				FLsetTextSize 12, gihDefaultDur$S



;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			File Time Point Sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

idFTP$S.00	     FLvalue	" ", 34, 25, gixF, giyF
gkFTP$S.00, gihFTP$S.00 FLslider   "File time point 0" , .001, 4, 0 ,	23, idFTP$S.00 , 230,25, gixF+40,giyF
idFTP$S.01	     FLvalue	" ", 34, 25, gixF, giyF+40
gkFTP$S.01, gihFTP$S.01 FLslider   "File time point 1" , .001, 4, 0 ,	23, idFTP$S.01 , 230,25, gixF+40,giyF+40
idFTP$S.02	     FLvalue	" ", 34, 25, gixF, giyF + 80
gkFTP$S.02, gihFTP$S.02 FLslider   "File time point 2" , .001, 4, 0 ,	23, idFTP$S.02 , 230,25, gixF+40,giyF+80
idFTP$S.03	     FLvalue	" ", 34, 25, gixF, giyF + 120
gkFTP$S.03, gihFTP$S.03 FLslider   "File time point 3" , .001, 4, 0 ,	23, idFTP$S.03 , 230,25, gixF+40,giyF+120
idFTP$S.04	     FLvalue	" ", 34, 25, gixF, giyF + 160
gkFTP$S.04, gihFTP$S.04 FLslider   "File time point 4" , .001, 4, 0 ,	23, idFTP$S.04 , 230,25, gixF+40,giyF+160
idFTP$S.05	     FLvalue	" ", 34, 25, gixF, giyF + 200
gkFTP$S.05, gihFTP$S.05 FLslider   "File time point 5" , .001, giend$S , 0 ,	23, idFTP$S.05 , 230,25, gixF+40,giyF+200
idFTP$S.06	     FLvalue	" ", 34, 25, gixF, giyF + 240
gkFTP$S.06, gihFTP$S.06 FLslider   "File time point 6" , .001, giend$S , 0 ,	23, idFTP$S.06 , 230,25, gixF+40,giyF+240

	FLsetVal_i	0     , gihFTP$S.00
	FLsetVal_i	.2683 , gihFTP$S.01
	FLsetVal_i	.5366 , gihFTP$S.02
	FLsetVal_i	.8049 , gihFTP$S.03
	FLsetVal_i	1.0732, gihFTP$S.04
	FLsetVal_i	1.3415, gihFTP$S.05
	FLsetVal_i	1.61  , gihFTP$S.06


gidFL$S				FLvalue	"Phrase duration", 40, 25, gixF + 20,  giyF + 330
gkFileLen$S , gidFileLen$S 	FLslider "" , 0, 20, 0 ,23, gidFL$S , 230,230, gixF -40,giyF-40
		FLhide		gidFileLen$S 
		FLsetVal_i	1.7, gidFileLen$S
		FLsetTextSize 	12,  gidFL$S

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Segment Stretch Sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

gixS	=	295
giyS	=	90

iminstretch=	.01
imaxstretch=	100
iexpon	=	-1;	=0 => linear, =-1 => exponential

idSFS$S.01	    	FLvalue		" ", 34, 25, gixS, giyS
gkSFS$S.01 , gihSFS$S.01 	FLslider        "<-Factor---STRETCH---Duration->" , iminstretch, imaxstretch, iexpon ,23, idSFS$S.01 , 230,25, gixS+39,giyS
idSFS$S.02	    	FLvalue		" ", 34, 25, gixS, giyS+40
gkSFS$S.02 , gihSFS$S.02 	FLslider        "<-Factor---STRETCH---Duration->" , iminstretch, imaxstretch, iexpon ,23, idSFS$S.02 , 230,25, gixS+39,giyS+40
idSFS$S.03	    	FLvalue		" ", 34, 25, gixS, giyS+80
gkSFS$S.03 , gihSFS$S.03 	FLslider        "<-Factor---STRETCH---Duration->" , iminstretch, imaxstretch, iexpon ,23, idSFS$S.03 , 230,25, gixS+39,giyS+80
idSFS$S.04	    	FLvalue		" ", 34, 25, gixS, giyS+120
gkSFS$S.04 , gihSFS$S.04 	FLslider        "<-Factor---STRETCH---Duration->" , iminstretch, imaxstretch, iexpon ,23, idSFS$S.04 , 230,25, gixS+39,giyS+120
idSFS$S.05	    	FLvalue		" ", 34, 25, gixS, giyS+160
gkSFS$S.05 , gihSFS$S.05 	FLslider        "<-Factor---STRETCH---Duration->" , iminstretch, imaxstretch, iexpon ,23, idSFS$S.05 , 230,25, gixS+39,giyS+160
idSFS$S.06	    	FLvalue		" ", 34, 25, gixS, giyS+200
gkSFS$S.06 , gihSFS$S.06 	FLslider        "<-Factor---STRETCH---Duration->" , iminstretch, imaxstretch, iexpon ,23, idSFS$S.06 , 230,25, gixS+39,giyS+200
	  FLsetVal_i	1, gihSFS$S.01
	  FLsetVal_i	1, gihSFS$S.02
	  FLsetVal_i	1, gihSFS$S.03
	  FLsetVal_i	1, gihSFS$S.04
	  FLsetVal_i	1, gihSFS$S.05
	  FLsetVal_i	1, gihSFS$S.06

gihSFSDur$S.01	FLvalue	"", 34, 25, gixS + 274, iyP
gkSFSDum$S.01 , giSFSDum$S.01	FLslider " ", 0, 30, 0, 1, gihSFSDur$S.01 , 10, 10
gihSFSDur$S.02	FLvalue	"", 34, 25, gixS + 274, iyP + 40
gkSFSDum$S.02 , giSFSDum$S.02	FLslider " ", 0, 30, 0, 1, gihSFSDur$S.02 , 10, 10
gihSFSDur$S.03	FLvalue	"", 34, 25, gixS + 274, iyP + 80
gkSFSDum$S.03 , giSFSDum$S.03	FLslider " ", 0, 30, 0, 1, gihSFSDur$S.03 , 10, 10
gihSFSDur$S.04	FLvalue	"", 34, 25, gixS + 274, iyP + 120
gkSFSDum$S.04 , giSFSDum$S.04	FLslider " ", 0, 430, 0, 1, gihSFSDur$S.04 , 10, 10
gihSFSDur$S.05	FLvalue	"", 34, 25, gixS + 274, iyP + 160
gkSFSDum$S.05 , giSFSDum$S.05	FLslider " ", 0, 30, 0, 1, gihSFSDur$S.05 , 10, 10
gihSFSDur$S.06	FLvalue	"", 34, 25, gixS + 274, iyP + 200
gkSFSDum$S.06 , giSFSDum$S.06	FLslider " ", 0, 30, 0, 1, gihSFSDur$S.06 , 10, 10

gihTotDur$S	FLvalue	"Tot dur", 34, 25, gixS + 274, iyP + 240
gkTotDum$S , giTotDum$S	FLslider "", 0, 60, 0, 1, gihTotDur$S , 10, 10

		FLhide	giSFSDum$S.01
		FLhide	giSFSDum$S.02
		FLhide	giSFSDum$S.03
		FLhide	giSFSDum$S.04
		FLhide	giSFSDum$S.05
		FLhide	giSFSDum$S.06

		FLhide	giTotDum$S

		FLsetVal_i	.268, giSFSDum$S.01
		FLsetVal_i	.268, giSFSDum$S.02
		FLsetVal_i	.268, giSFSDum$S.03
		FLsetVal_i	.268, giSFSDum$S.04
		FLsetVal_i	.268, giSFSDum$S.05
		FLsetVal_i	.268, giSFSDum$S.06
initTotDur	=	.286*6
		FLsetVal_i	(initTotDur), giTotDum$S






;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Pitch Value Sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

iminpch	=	66
imaxpch	=	660
iexpP	=	-1
	

idPchVal$S.01	  		FLvalue	" ", 30, 25, ixP + 240, iyP
gkPchVal$S.01, gihPchVal$S.01 	FLslider       "Pitch 1" , iminpch, imaxpch, 	iexpP,23,idPchVal$S.01 , 230, 25, ixP ,iyP
idPchVal$S.02	  		FLvalue	" ", 30, 25, ixP + 240, iyP + 40
gkPchVal$S.02, gihPchVal$S.02 	FLslider       "Pitch 2" , iminpch, imaxpch, 	iexpP,23,idPchVal$S.02 , 230, 25, ixP ,iyP + 40
idPchVal$S.03	  		FLvalue	" ", 30, 25, ixP + 240, iyP + 80
gkPchVal$S.03, gihPchVal$S.03 	FLslider       "Pitch 3" , iminpch, imaxpch, 	iexpP,23,idPchVal$S.03 , 230, 25, ixP ,iyP + 80
idPchVal$S.04	  		FLvalue	" ", 30, 25, ixP + 240, iyP + 120
gkPchVal$S.04, gihPchVal$S.04 	FLslider       "Pitch 4" , iminpch, imaxpch, 	iexpP,23,idPchVal$S.04 , 230, 25, ixP, iyP + 120
idPchVal$S.05	  		FLvalue	" ", 30, 25, ixP + 240, iyP + 160
gkPchVal$S.05, gihPchVal$S.05 	FLslider       "Pitch 5" , iminpch, imaxpch, 	iexpP,23,idPchVal$S.05 , 230, 25, ixP, iyP + 160
idPchVal$S.06	  		FLvalue	" ", 30, 25, ixP + 240, iyP + 200
gkPchVal$S.06, gihPchVal$S.06 	FLslider       "Pitch 6" , iminpch, imaxpch, 	iexpP,23,idPchVal$S.06 , 230, 25, ixP, iyP + 200

gihPchName$S.01			FLbox 	80000, 3, 1, 14, 34, 25, ixP + 280, iyP 
gihPchName$S.02 			FLbox 	80000, 3, 1, 14, 34, 25, ixP + 280, iyP + 40
gihPchName$S.03 			FLbox 	80000, 3, 1, 14, 34, 25, ixP + 280, iyP + 80
gihPchName$S.04 			FLbox 	80000, 3, 1, 14, 34, 25, ixP + 280, iyP + 120
gihPchName$S.05 			FLbox 	80000, 3, 1, 14, 34, 25, ixP + 280, iyP + 160
gihPchName$S.06 			FLbox 	80000, 3, 1, 14, 34, 25, ixP + 280, iyP + 200

				FLsetVal_i	200,	gihPchVal$S.01
				FLsetVal_i	200,	gihPchVal$S.02
				FLsetVal_i	200,	gihPchVal$S.03
				FLsetVal_i	200,	gihPchVal$S.04
				FLsetVal_i	200,	gihPchVal$S.05
				FLsetVal_i	200,	gihPchVal$S.06

gkMeanPch$S , gihMeanPch$S	FLbutton	"Mean"  	,1, 0, 1, 55, 40, ixP + 335 , iyP + 40, 0, 45, 0, 2, $S
				FLsetTextSize 12, gihMeanPch$S

gkTune$S , gihTune$S		FLbutton	"Tune"  	,1, 0, 1, 55, 40, ixP + 335 , iyP + 120, 0, 46, 0, 0, $S
				FLsetTextSize 12, gihTune$S


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Diverse sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


idRange$S		FLvalue		" ", 30, 25, ixP - 2,   iyP + 242
gkRange$S ,  gihRange$S 	FLslider    	"Range" 	, -3, 3, 0 ,  24, idRange$S ,   25, 120, ixP ,    iyP + 272
idTransp$S		FLvalue		" ", 30, 25, ixP + 58,  iyP + 242
gkTransp$S , gihTransp$S	FLslider    	"Transpose"	, -20, 20, 0, 24, idTransp$S ,  25, 120, ixP+60,  iyP + 272
idNoise$S		FLvalue		" ", 30, 25, ixP + 118, iyP + 242
gkNoise$S ,  gihNoise$S 	FLslider    	"Noise/buzz"	, 0, 1, 0 ,   24, idNoise$S ,   25, 120, ixP+120 ,iyP + 272
idPchSrc$S		FLvalue		" ", 30, 25, ixP + 178, iyP + 242
gkPchSrc$S , gihPchSrc$S FLslider    	"Pitch\nsource"	, 0, 1, 0 ,   24, idPchSrc$S ,  25, 120, ixP+180 , iyP + 272
idPort$S	    	FLvalue		" ", 30, 25, ixP + 237, iyP + 242
gkPort$S , gihPort$S	FLslider	"Portamento"	, .05, 5, 0 ,  24, idPort$S ,    25, 120, ixP+240 , iyP + 272
idFrqShift$S	    	FLvalue		" ", 30, 25, ixP + 297, iyP + 242
gkFrqShift$S , gihFrqShift$S \
			FLslider	"Spectral\nshift", .25, 4, 0 ,  24, idFrqShift$S , 25,120, ixP+300 ,iyP + 272

idDelay$S	    	FLvalue		" ", 30, 25, gixS, giyS+350
gkDelay$S ,  gihDelay$S	FLslider	"Delay"		, 0, 10, 0 ,  23, idDelay$S ,  230, 25, gixS+40 ,iyP + 350

;gkPort$S, gihPort$S		FLslider	"Portamento", .01, 2, 0, 1, -1, 40, ixP + 280, iyP + 270
			FLsetTextSize 11, gihRange$S
			FLsetTextSize 11, gihTransp$S
			FLsetTextSize 11, gihNoise$S
			FLsetTextSize 11, gihPchSrc$S
			FLsetTextSize 11, gihDelay$S
			FLsetTextSize 11, gihPort$S
			FLsetTextSize 11, gihFrqShift$S

;gkFrqShift$S, gihFrqShift$S	FLknob		"Spectral shift", .25, 4, -1, 1, -1, 40, ixP + 280, iyP + 330
				
				

	FLsetVal_i	1, gihRange$S
	FLsetVal_i	0, gihTransp$S
	FLsetVal_i	1, gihNoise$S
	FLsetVal_i	1, gihPchSrc$S
	FLsetVal_i	0, gihDelay$S
	FLsetVal_i	.1, gihPort$S
	FLsetVal_i	1, gihFrqShift$S


; Displays the text of the poem
gihText$S 		FLbox 10001, 1, 1, 14, 300, 25, 10, giyF + 300


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Phrase counter
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

gkPhrase$S , gihPhrase$S FLcount  "Phrase No", 1, 21, 1, 4, 1, 140, 50, gixF+75 , giyS+300, 105, 7$S , 0, .01  	; triggers control instrument 71-78 to make ktrig=1 for setting gk6 to giend    
	  FLsetVal_i 	1, gihPhrase$S

#
