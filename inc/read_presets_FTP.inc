
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

;read_presets_FTP.inc

#define PRESETREAD_FTP(fp)
#
i$fp.11	tab_i	$fp.11, ifn
i$fp.12	tab_i	$fp.12, ifn
i$fp.13	tab_i	$fp.13, ifn
i$fp.14	tab_i	$fp.14, ifn
i$fp.15	tab_i	$fp.15, ifn
i$fp.16	tab_i	$fp.16, ifn
i$fp.17	tab_i	$fp.17, ifn


FLsetVal_i	i$fp.11, gihFTP$fp.00
FLsetVal_i	i$fp.12, gihFTP$fp.01
FLsetVal_i	i$fp.13, gihFTP$fp.02
FLsetVal_i	i$fp.14, gihFTP$fp.03
FLsetVal_i	i$fp.15, gihFTP$fp.04
FLsetVal_i	i$fp.16, gihFTP$fp.05
FLsetVal_i	i$fp.17, gihFTP$fp.06

#

