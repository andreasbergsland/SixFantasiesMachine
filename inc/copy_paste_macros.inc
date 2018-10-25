
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

;copy_paste_macros.inc


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Copy & paste macros
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

; Defines macros for copy and paste of variables

#define	COPYFTP(cf)
#
giFTP0		=	i(gkFTP$cf.00)
giFTP1		=	i(gkFTP$cf.01)
giFTP2		=	i(gkFTP$cf.02)
giFTP3		=	i(gkFTP$cf.03)
giFTP4		=	i(gkFTP$cf.04)
giFTP5		=	i(gkFTP$cf.05)
giFTP6		=	i(gkFTP$cf.06)
#

#define	PASTEFTP(pf)
#
FLsetVal_i	giFTP0, gihFTP$pf.00
FLsetVal_i	giFTP1, gihFTP$pf.01
FLsetVal_i	giFTP2, gihFTP$pf.02
FLsetVal_i	giFTP3, gihFTP$pf.03
FLsetVal_i	giFTP4, gihFTP$pf.04
FLsetVal_i	giFTP5, gihFTP$pf.05
FLsetVal_i	giFTP6, gihFTP$pf.06
#

#define	COPYSFS(cs)
#
giSFS1		=	i(gkSFS$cs.01)
giSFS2		=	i(gkSFS$cs.02)
giSFS3		=	i(gkSFS$cs.03)
giSFS4		=	i(gkSFS$cs.04)
giSFS5		=	i(gkSFS$cs.05)
giSFS6		=	i(gkSFS$cs.06)
#

#define	PASTESFS(ps)
#
FLsetVal_i	giSFS1, gihSFS$ps.01
FLsetVal_i	giSFS2, gihSFS$ps.02
FLsetVal_i	giSFS3, gihSFS$ps.03
FLsetVal_i	giSFS4, gihSFS$ps.04
FLsetVal_i	giSFS5, gihSFS$ps.05
FLsetVal_i	giSFS6, gihSFS$ps.06
#

#define	COPYPchVal(cp)
#
giPch1		=	i(gkPchVal$cp.01)
giPch2		=	i(gkPchVal$cp.02)
giPch3		=	i(gkPchVal$cp.03)
giPch4		=	i(gkPchVal$cp.04)
giPch5		=	i(gkPchVal$cp.05)
giPch6		=	i(gkPchVal$cp.06)
#

#define	PASTEPchVal(pp)
#
FLsetVal_i	giPch1, gihPchVal$pp.01
FLsetVal_i	giPch2, gihPchVal$pp.02
FLsetVal_i	giPch3, gihPchVal$pp.03
FLsetVal_i	giPch4, gihPchVal$pp.04
FLsetVal_i	giPch5, gihPchVal$pp.05
FLsetVal_i	giPch6, gihPchVal$pp.06
#


#define COPYDiv(cd)
#
giDelay		=	i(gkDelay$cd )
giRange		=	i(gkRange$cd )
giTransp	=	i(gkTransp$cd )
giNoise		=	i(gkNoise$cd )
giPchSrc	=	i(gkPchSrc$cd )
giPort		=	i(gkPort$cd )
giFrqShift	=	i(gkFrqShift$cd )
#

#define	PASTEDiv(pd)
#
FLsetVal_i	giDelay,  gihDelay$pd
FLsetVal_i	giRange,  gihRange$pd
FLsetVal_i	giTransp, gihTransp$pd
FLsetVal_i	giNoise,  gihNoise$pd
FLsetVal_i	giPchSrc, gihPchSrc$pd
FLsetVal_i	giPort,   gihPort$pd
FLsetVal_i	giFrqShift,gihFrqShift$pd
#

#define DefaultDur(DD)
#
FLsetVal_i	1, gihSFS$DD.01
FLsetVal_i	1, gihSFS$DD.02
FLsetVal_i	1, gihSFS$DD.03
FLsetVal_i	1, gihSFS$DD.04
FLsetVal_i	1, gihSFS$DD.05
FLsetVal_i	1, gihSFS$DD.06
#