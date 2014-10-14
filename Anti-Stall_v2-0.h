// ANTI-STALL FUNCTION
//
// VERSION -- 2.0
//
// DESCRIPTION -- This is the function we use for anti-stall. Uses the 4th timer on the NXT for no interference
//
// CHANGE LOG
//   1.0 -- Created
//
//   1.0.1 -- Fixed a few bugs
//
//   1.1 -- Slightly redesigned the algorithm so that the function is more effecient and runs more smoothly
//
//   2.0 -- Updated code for RobotC v4.26. Changed to return a boolean value for use in loops. Optimized code for
//          more effeciency and now values feed in through parameters, so this function can be used with any
//          sensor/encoder input.
#ifndef ANTI_STALL
#define ANTI_STALL

#define INTERVAL 500                            // Time interval //

static bool stall_last_interval = false;
static float overall_distance;
static float distance;
static float rate;
static float lastRate;
static float stall_trigger;

bool stall_occured(float sensorInput){
	if(time1[T4] < INTERVAL) {}
	else if(time1[T4] >= INTERVAL){
		distance = abs(sensorInput);
		rate = abs(distance - overall_distance);
	stall_trigger = (stall_last_interval == false) ? lastRate*0.5 : lastRate*1.2;
		if(rate <= stall_trigger){
			stall_last_interval = true;
		}
		else{
			stall_last_interval = false;
		}
		overall_distance = distance;
		lastRate = rate;
		ClearTimer(T4);
	}
	return stall_last_interval;
}
#endif // ANTI_STALL DEFINITION
