
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

;"inc/global variables.inc"


#define GLOBAL(T)
#
giend$T		init	4
gkFTP$T.00	init	0
gkFTP$T.01	init	0.2683
gkFTP$T.02	init	0.5366
gkFTP$T.03	init	0.8049
gkFTP$T.04	init	1.0732
gkFTP$T.05	init	1.3415
gkFTP$T.06	init	1.61
gkSFS$T.01	init	1
gkSFS$T.02	init	1
gkSFS$T.03	init	1
gkSFS$T.04	init	1
gkSFS$T.05	init	1
gkSFS$T.06	init	1
gkPchVal$T.01	init	180
gkPchVal$T.02	init	180
gkPchVal$T.03	init	180
gkPchVal$T.04	init	180
gkPchVal$T.05	init	180
gkPchVal$T.06	init	180
gkRange$T	init	0
gkPort$T	init	.1
gkFrqShift$T	init	1
gkTransp$T	init	1
gkDelay$T	init	1
gkOnOff$T	init	1
gkActive$T	init	0
gkRevMix$T	init	1
gkVol$T		init	1
gkNoiz$T	init	1
gkPan$T		init	.5
gkChorus$T	init	0
gkPhrase$T	init	1
gktrig$T	init 	0
giFTP$T.O1	init	0
giFTP$T.O2	init	0
giFTP$T.O3	init	0
giFTP$T.O4	init	0
giFTP$T.O5	init	0
giFTP$T.O6	init	0
giFTP$T.O0	init	0
giSFS$T.O1	init	0
giSFS$T.O2	init	0
giSFS$T.O3	init	0
giSFS$T.O4	init	0
giSFS$T.O5	init	0
gidFileLen$T	init	1.7
giPchName$T.01	init	80001
giPchName$T.02	init	80001
giPchName$T.03	init	80001
giPchName$T.04	init	80001
giPchName$T.05	init	80001
giPchName$T.06	init	80001
gkSliderIn	init	0
gkdur$T		init	1.61
gkdur$T.01	init	.2683
gkdur$T.02	init	.2683
gkdur$T.03	init	.2683
gkdur$T.04	init	.2683
gkdur$T.05	init	.2683
gkdur$T.06	init	.2683
gkSFSDum$T.01	init	.2683
gkSFSDum$T.02	init	.2683
gkSFSDum$T.03	init	.2683
gkSFSDum$T.04	init	.2683
gkSFSDum$T.05	init	.2683
gkSFSDum$T.06	init	.2683
gkFilterMix$T	init	0.0
#

#define	FILTERMACROS(V ' T)
#
gkFilterType$V._$T	init	1
gkDecayTime$V._$T	init	2
gkFilterPitch$V._$T	init	7.00
gkBand$V._$T		init	.005
gkFilterGain$V._$T	init	1
gkFilterOn$V._$T		init	0
#

#define FILTERMACROSMACRO(Num)
#
$FILTERMACROS($Num'1)
$FILTERMACROS($Num'2)
$FILTERMACROS($Num'3)
$FILTERMACROS($Num'4)
$FILTERMACROS($Num'5)
$FILTERMACROS($Num'6)
$FILTERMACROS($Num'7)
$FILTERMACROS($Num'8)
$FILTERMACROS($Num'9)
#

$FILTERMACROSMACRO(1)
$FILTERMACROSMACRO(2)
$FILTERMACROSMACRO(3)
$FILTERMACROSMACRO(4)
$FILTERMACROSMACRO(5)
$FILTERMACROSMACRO(6)
$FILTERMACROSMACRO(7)
$FILTERMACROSMACRO(8)

$GLOBAL(1)
$GLOBAL(2)
$GLOBAL(3)
$GLOBAL(4)
$GLOBAL(5)
$GLOBAL(6)
$GLOBAL(7)
$GLOBAL(8)

#define		INITCOPY(F)
#
giFTP$F		init	0
giSFS$F		init	0
giPch$F		init	0
#

$INITCOPY(1)
$INITCOPY(2)
$INITCOPY(3)
$INITCOPY(4)
$INITCOPY(5)
$INITCOPY(6)


giDelay		init	0
giRange		init	1
giTransp	init	1
giNoise		init	0
giPchSrc	init	0
giPort		init	.1
giFrqShift	init	1

gkPresN		init	1
gkPreStor	init	1
gkPreRead	init	1
gkPreSav	init	1
gkPreOpn	init	1
gkLoop		init	1
gkPlay		init	0
gkFilterOn	init	0

gkGlobalTime	init	0

gifil1		init	0.1
gifil2		init	0.2
gifil3		init	0.3
gifil4		init	0.4
gifil5		init	3
gktrig		init 	0


gkmeanpch	init	0
gkpitch		init	0
gkpitch1	init	0
gkpitch2	init	0
gkpitch3	init	0
gkpitch4	init	0
gkpitch5	init	0
gkpitch6	init	0
gkpitch7	init	0
gkpitch8	init	0

gktrig2		init 	0
gitotdur	init	.3
giFileNum	init	1
gkWFile		init	0