##
##	This file is part of qpOASES.
##
##	qpOASES -- An Implementation of the Online Active Set Strategy.
##	Copyright (C) 2007-2012 by Hans Joachim Ferreau, Andreas Potschka,
##	Christian Kirches et al. All rights reserved.
##
##	qpOASES is free software; you can redistribute it and/or
##	modify it under the terms of the GNU Lesser General Public
##	License as published by the Free Software Foundation; either
##	version 2.1 of the License, or (at your option) any later version.
##
##	qpOASES is distributed in the hope that it will be useful,
##	but WITHOUT ANY WARRANTY; without even the implied warranty of
##	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
##	See the GNU Lesser General Public License for more details.
##
##	You should have received a copy of the GNU Lesser General Public
##	License along with qpOASES; if not, write to the Free Software
##	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
##



##
##	Filename:  Makefile
##	Author:    Hans Joachim Ferreau
##	Version:   3.0beta
##	Date:      2007-2012
##


##
##	targets
##


all: src examples 
#src_aw testing

src:
	@cd $@; ${MAKE} -s 

src_aw:
	@cd $@; ${MAKE} -s 

examples:
	@cd $@; ${MAKE} -s

testing:
	@cd $@; ${MAKE} -s 

doc:
	@cd $@; ${MAKE} -s 

clean:
	@  cd src               && ${MAKE} -s clean && cd .. \
	&& cd src_aw            && ${MAKE} -s clean && cd .. \
	&& cd examples          && ${MAKE} -s clean && cd .. \
	&& cd testing           && ${MAKE} -s clean && cd .. \
	&& cd bin               && rm -f * && cd ..

clobber: clean


.PHONY : all src src_aw examples testing doc clean clobber


##
##   end of file
##
