
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

;read_presets.inc


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;			Read Preset Values - Set sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define	PRESETREAD(F)
#
i$F.01	tab_i	$F.01, ifn	; Voice On/off
i$F.02	tab_i	$F.02, ifn	; Voice volume
i$F.03	tab_i	$F.03, ifn	; Voice chorus
i$F.04	tab_i	$F.04, ifn	; Voice wet/dry mix
i$F.05	tab_i	$F.05, ifn	; Voice pan
i$F.06	tab_i	$F.06, ifn	; Voice noise level


;i$F11	tab_i	$F11, ifn
;i$F12	tab_i	$F12, ifn
;i$F13	tab_i	$F13, ifn
;i$F14	tab_i	$F14, ifn
;i$F15	tab_i	$F15, ifn
;i$F16	tab_i	$F16, ifn

i$F.21	tab_i	$F.21, ifn	; Stretch factor 1
i$F.22	tab_i	$F.22, ifn	; Stretch factor 2
i$F.23	tab_i	$F.23, ifn	; Stretch factor 3
i$F.24	tab_i	$F.24, ifn	; Stretch factor 4
i$F.25	tab_i	$F.25, ifn	; Stretch factor 5
i$F.26	tab_i	$F.26, ifn	; Stretch factor 6	

i$F.31	tab_i	$F.31, ifn	; Pitch value 1
i$F.32	tab_i	$F.32, ifn	; Pitch value 2
i$F.33	tab_i	$F.33, ifn	; Pitch value 3
i$F.34	tab_i	$F.34, ifn	; Pitch value 4
i$F.35	tab_i	$F.35, ifn	; Pitch value 5
i$F.36	tab_i	$F.36, ifn	; Pitch value 6

i$F.41	tab_i	$F.41, ifn	; Delay
i$F.42	tab_i	$F.42, ifn	; Range
i$F.43	tab_i	$F.43, ifn	; Transposition
i$F.44	tab_i	$F.44, ifn	; Noise/buzz balance
i$F.45	tab_i	$F.45, ifn	; Pitch source
i$F.46	tab_i	$F.46, ifn	; Portamento
i$F.47	tab_i	$F.47, ifn	; Spectral shift

i$F.50	tab_i	$F.50, ifn	; Phrase number


FLsetVal_i	i$F.01, gihActive$F
FLsetVal_i	i$F.02, gihVol$F
FLsetVal_i	i$F.03, gihChorus$F
FLsetVal_i	i$F.04, gihRevMix$F
FLsetVal_i	i$F.05, gihPan$F
FLsetVal_i	i$F.06, gihNoiz$F

;FLsetVal_i	i$F11, gihFTP$F00
;FLsetVal_i	i$F11, gihFTP$F01
;FLsetVal_i	i$F11, gihFTP$F02
;FLsetVal_i	i$F11, gihFTP$F03
;FLsetVal_i	i$F11, gihFTP$F04
;FLsetVal_i	i$F11, gihFTP$F05

FLsetVal_i	i$F.21, gihSFS$F.01
FLsetVal_i	i$F.22, gihSFS$F.02
FLsetVal_i	i$F.23, gihSFS$F.03
FLsetVal_i	i$F.24, gihSFS$F.04
FLsetVal_i	i$F.25, gihSFS$F.05
FLsetVal_i	i$F.26, gihSFS$F.06

FLsetVal_i	i$F.31, gihPchVal$F.01
FLsetVal_i	i$F.32, gihPchVal$F.02
FLsetVal_i	i$F.33, gihPchVal$F.03
FLsetVal_i	i$F.34, gihPchVal$F.04
FLsetVal_i	i$F.35, gihPchVal$F.05
FLsetVal_i	i$F.36, gihPchVal$F.06

FLsetVal_i	i$F.41, gihDelay$F
FLsetVal_i	i$F.42, gihRange$F
FLsetVal_i	i$F.43, gihTransp$F
FLsetVal_i	i$F.44, gihNoise$F
FLsetVal_i	i$F.45, gihPchSrc$F
FLsetVal_i	i$F.46, gihPort$F
FLsetVal_i	i$F.47, gihFrqShift$F


FLsetVal_i	i$F.50, gihPhrase$F

#
