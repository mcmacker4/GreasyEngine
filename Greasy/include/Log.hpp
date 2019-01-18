
#include <iostream>

#if GR_DEBUG
	#define GR_LOG_DEBUG(MSG)	std::cout << "[DEBUG] "		<< MSG << std::endl
	#define GR_LOG_INFO(MSG)	std::cout << "[INFO] "		<< MSG << std::endl
	#define GR_LOG_WARN(MSG)	std::cout << "[WARNING] "	<< MSG << std::endl
	#define GR_LOG_ERROR(MSG)	std::cout << "[ERROR] "		<< MSG << std::endl
#else
	#define GR_LOG_DEBUG(MSG)
	#define GR_LOG_INFO(MSG)
	#define GR_LOG_WARN(MSG)
	#define GR_LOG_ERROR(MSG)
#endif