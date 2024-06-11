struct Stopwatch{
	chrono::steady_clock::time_point start;
	Stopwatch():start(chrono::steady_clock::now()){}

	int msec(){
		auto now = chrono::steady_clock::now();
		return int(chrono::duration_cast<chrono::milliseconds>(now-start).count());
	}
};
