
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

;set_FTPvals_in_sliders.inc


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;		Set time pointer values in sliders
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		instr 	   71
$FILELENGTH(1)
		endin

		instr 	   72
$FILELENGTH(2)		
		endin

		instr 	   73
$FILELENGTH(3)	
		endin

		instr 	   74
$FILELENGTH(4)
		endin

		instr 	   75
$FILELENGTH(5)
		endin

		instr 	   76
$FILELENGTH(6)
		endin

		instr 	   77
$FILELENGTH(7)
		endin

		instr 	   78
$FILELENGTH(8)
		endin
