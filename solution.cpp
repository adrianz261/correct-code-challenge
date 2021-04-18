int parseQuantity(const char* str) {
    constexpr int maxInt = []() -> int {   
        switch (sizeof(int)) {
            case 2:
                return 32'767;
            case 4:
                return 2'147'483'647;
            case 8:
                return 9'223'372'036'854'775'807;
            default:
                return 2'147'483'647;
        }
    }();


    int result = 0;
    for (int i = 0;; i++) {
        int value = str[i] - '0';
        if (value >= 0 && value <= 9 && result <= (maxInt - value) / 10) {  // overflow check
            result = 10 * result + value;
        } else {
            return result;
        }
    }
}
