/*
 *	This file is part of qpOASES.
 *
 *	qpOASES -- An Implementation of the Online Active Set Strategy.
 *	Copyright (C) 2007-2012 by Hans Joachim Ferreau, Andreas Potschka,
 *	Christian Kirches et al. All rights reserved.
 *
 *	qpOASES is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation; either
 *	version 2.1 of the License, or (at your option) any later version.
 *
 *	qpOASES is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *	See the GNU Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU Lesser General Public
 *	License along with qpOASES; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *	\file examples/runAllOqpExamples.cpp
 *	\author Hans Joachim Ferreau
 *	\version 3.0beta
 *	\date 2013
 *
 *	Use qpOASES for solving all QP sequences of the Online QP Benchmark 
 *	Collection. In order to run it, you have to download all examples
 *	from http://homes.esat.kuleuven.be/~optec/software/onlineQP/.
 */



#include <qpOASES.hpp>


/** Example for qpOASES main function using the OQP interface. */
int main( )
{
	USING_NAMESPACE_QPOASES

	/* 1) Define benchmark arguments. */
	BooleanType isSparse     = BT_FALSE;
	BooleanType useHotstarts;

	Options options;
	options.setToMPC();
	options.printLevel = PL_LOW;

	int maxAllowedNWSR;
	real_t maxNWSR, avgNWSR, maxCPUtime, avgCPUtime;
	real_t maxPrimalDeviation, maxDualDeviation, maxObjDeviation;

	const int numBenchmarks = 5;
	const char *benchmarkPath[numBenchmarks];
	benchmarkPath[0] = "./chain80/";
	benchmarkPath[1] = "./chain80w/";
	benchmarkPath[2] = "./diesel/";
	benchmarkPath[3] = "./crane/";
	benchmarkPath[4] = "./CDU/";


	/* 2) Run all benchmarks in a loop */
	for ( int ii=0; ii<2*numBenchmarks; ++ii )
	{
		if ( ii%2 == 0 )
			useHotstarts = BT_FALSE;
		else
			useHotstarts = BT_TRUE;
		
		maxAllowedNWSR = 1000;
		maxNWSR = 0.0;
		avgNWSR = 0.0;
		maxCPUtime = 1000.0; /* seconds */
		avgCPUtime =    0.0; /* seconds */
		maxPrimalDeviation = 0.0;
		maxDualDeviation   = 0.0;
		maxObjDeviation    = 0.0;

		if ( runOQPbenchmark(	benchmarkPath[ii/2],
								isSparse,useHotstarts,
								options,maxAllowedNWSR,
								maxNWSR,avgNWSR,maxCPUtime,avgCPUtime,
								maxPrimalDeviation,maxDualDeviation,maxObjDeviation
								) != SUCCESSFUL_RETURN )
		{
			myPrintf( "In order to run this example, you need to download example no. 02\nfrom the Online QP Benchmark Collection website first!\n" );
			return -1;
		}

		/* 3) Print results. */
		printf( "\n\n" );
		if ( useHotstarts == BT_FALSE )
			printf( "OQP Benchmark Results for %s (cold-starts):\n", benchmarkPath[ii/2] );
		else
			printf( "OQP Benchmark Results for %s (hot-starts):\n", benchmarkPath[ii/2] );

		printf( "=======================================================\n\n" );
		//printf( "maximum CPU time:             %.2f milliseconds\n",1000.0*maxCPUtime );
		//printf( "average CPU time:             %.2f milliseconds\n",1000.0*avgCPUtime );
		//printf( "\n" );
		printf( "maximum iterations:           %.1f\n",maxNWSR );
		printf( "average iterations:           %.1f\n",avgNWSR );
		printf( "\n" );
		//printf( "maximum primal deviation:     %.2e\n",maxPrimalDeviation );
		//printf( "maximum dual deviation:       %.2e\n",maxDualDeviation );
		//printf( "maximum objective deviation:  %.2e\n",maxObjDeviation );
		//printf( "\n" );
	}
	
	return 0;
}


/*
 *	end of file
 */
