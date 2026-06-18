class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the positions relative to 0 degrees (12 o'clock)
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        // Find the absolute difference
        double diff = abs(hourAngle - minuteAngle);
        
        // Return the smaller angle
        return min(diff, 360.0 - diff);
    }
};