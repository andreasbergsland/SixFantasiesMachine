
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

;"voice_controls.inc"


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Voice Controls
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define VOICECONTROLS(N)
; Buttons for all tabs
#
iVoiceY_pos	=	565
iKnobsDist	=	55
iVoiceTxtSize	=	11

gkActive$N , gihActive$N FLbutton	"On/off"  	,1, 0, 2, 50, 30,    ($N * 80)-45, iVoiceY_pos - 40, -1
gkVol$N,    gihVol$N	FLknob 		"Volume"	,0, 2, 0, 1, -1, 40, ($N * 80)-45, iVoiceY_pos + iKnobsDist*0
gkNoiz$N,   gihNoiz$N	FLknob		"NoiseVol" 	,.05,1,0, 1, -1, 40, ($N * 80)-45, iVoiceY_pos + iKnobsDist*1
gkChorus$N , gihChorus$N	FLknob		"Chorus"	,0, 1, 0, 1, -1, 40, ($N * 80)-45, iVoiceY_pos + iKnobsDist*2
gkRevMix$N , gihRevMix$N	FLknob		"Wet/dry"	,0, 1, 0, 1, -1, 40, ($N * 80)-45, iVoiceY_pos + iKnobsDist*3
gkPan$N ,    gihPan$N	FLknob		"Pan"		,0, 1, 0, 1, -1, 40, ($N * 80)-45, iVoiceY_pos + iKnobsDist*4

			FLsetVal_i	1 , gihVol$N
			FLsetVal_i	.8, gihNoiz$N
			FLsetVal_i	0 , gihChorus$N
			FLsetVal_i	0 , gihRevMix$N
			FLsetVal_i	.5, gihPan$N
	
			FLsetTextSize 	iVoiceTxtSize, gihActive$N
			FLsetTextSize 	iVoiceTxtSize, gihVol$N
			FLsetTextSize 	iVoiceTxtSize, gihNoiz$N
			FLsetTextSize 	iVoiceTxtSize, gihChorus$N
			FLsetTextSize 	iVoiceTxtSize, gihRevMix$N
			FLsetTextSize 	iVoiceTxtSize, gihPan$N
			
	
#
