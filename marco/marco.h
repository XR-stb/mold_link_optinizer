#pragma once

#define CONTACT(x, y) x##y
#define FILE_UNIQUE_VAR CONTACT(_variant_, __LINE__)
