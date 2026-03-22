// Modify this file to change what commands output to your statusbar, and recompile using make
static const Block blocks[] = {
    /*Icon*/        /*Command*/                                                        /*Update Interval*/     /*Update Signal*/

    // CPU usage
    {"🌡️", "sensors | awk '/^CPU/ {gsub(\"\\+\", \"\"); print $2}'", 20, 0},

    // Memory usage
    {"💾 ",         "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",       30,                    0},

    // Battery stat
    {"🔋 ", "sh -c 'BATT=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | awk \"/percentage/ {p=\\$2} /state/ {s=\\$2} END {printf \\\"%s %s\\\", p, (s==\\\"charging\\\"?\\\"(C)\\\":\\\"(D)\\\")}\"); echo $BATT'", 30, 0},
    // Wi-Fi SSID / connection
    {"🛜", "nmcli -t -f active,ssid dev wifi | awk -F: '/^yes/ {print $2}' || echo 'x'", 5, 0},

    // Volume level
    {"🔊",         "amixer get Master | tail -n1 | awk -F'[][]' '{ print $2 }'",   1,                     0},

    // Date / Time
    {"",             "date '+%b %d (%a) %I:%M%p'",                                  5,                     0},
};

// sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
