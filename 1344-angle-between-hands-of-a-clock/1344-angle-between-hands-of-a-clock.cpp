class Solution {
public:
    double angleClock(int hour, int minutes) {
        double per_minute_shift=0.5;
        double hour_shift=(per_minute_shift)*(double(minutes));
        double minute_angle=6*minutes;
        double hour_angle=(hour*30)+hour_shift;
        double net_angle=hour_angle-minute_angle;
        if(abs(net_angle)<=180)
            return abs(net_angle);
        else
            return 360-abs(net_angle);
    }
};