string convertString(const std::string& str) {
    string result = str;

    // Convert the first character of the string to uppercase
    if (!result.empty() && islower(result[0])) {
        result[0] = toupper(result[0]);
    }

    // Convert the first character of each word to uppercase
    for (size_t i = 1; i < result.length(); i++) {
        if (isspace(result[i - 1]) && islower(result[i])) {
            result[i] = toupper(result[i]);
        }
    }

    return result;
}
