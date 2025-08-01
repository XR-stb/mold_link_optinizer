#pragma once

#define CONTACT3(x, y) x##y
#define CONTACT2(x, y) CONTACT3(x, y)
#define CONTACT1(x, y) CONTACT2(x, y)
#define CONTACT(x, y) CONTACT1(x, y)
#define FILE_UNIQUE_VAR CONTACT(_variant_, __LINE__)