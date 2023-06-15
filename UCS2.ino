String convertToUCS2String(String inputString) {
  String ucs2String = "";

  for (size_t i = 0; i < inputString.length(); i++) {
    // Convert each character to its corresponding UCS2 code
    uint16_t ucs2Code = inputString.charAt(i);

    String ucs2StringTemp = "";
    // Format the UCS2 code as \u0000 and append it to the UCS2 string
    ucs2StringTemp += String(ucs2Code, HEX);
    while (ucs2StringTemp.length() < 4) {
      ucs2StringTemp = "0" + ucs2StringTemp;
    }

    ucs2String += ucs2StringTemp;
  }

  return ucs2String;
}
