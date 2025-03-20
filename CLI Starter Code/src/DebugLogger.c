/**
 * \file
 *
 * \brief Debug Logger Module Implementation
 *
 * This module provides functions for logging messages at different severity levels.
 */

#include "DebugLogger.h"
#include "SerialConsole/SerialConsole.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * \brief Current log level
 *
 * Only messages with a level equal to or higher than this level will be printed.
 */
static enum eDebugLogLevels currentLogLevel = LOG_INFO_LVL;

/**
 * \brief Log level prefixes
 *
 * These prefixes are prepended to log messages for better readability.
 */
static const char* logLevelPrefixes[] = {
    "[INFO] ",
    "[DEBUG] ",
    "[WARNING] ",
    "[ERROR] ",
    "[FATAL] ",
    ""  // LOG_OFF_LVL doesn't need a prefix
};

/**
 * \brief Get the current log level
 *
 * \return Current log level
 */
enum eDebugLogLevels getLogLevel(void)
{
    return currentLogLevel;
}

/**
 * \brief Set the log level
 *
 * Only messages with a level equal to or higher than this level will be printed.
 *
 * \param debugLevel The new log level
 */
void setLogLevel(enum eDebugLogLevels debugLevel)
{
    if (debugLevel < N_DEBUG_LEVELS) {
        currentLogLevel = debugLevel;
    }
}

/**
 * \brief Log a message
 *
 * This function logs a message to the terminal if the provided log level is
 * equal to or higher than the current log level set by setLogLevel().
 *
 * \param level The log level of this message
 * \param format Format string (same as printf)
 * \param ... Variable arguments for format string
 */
void LogMessage(enum eDebugLogLevels level, const char *format, ...)
{
    // Check if the message should be printed
    if (level < currentLogLevel || level >= N_DEBUG_LEVELS) {
        return;
    }
    
    // Buffer for the formatted message
    char buffer[256];
    
    // Add the log level prefix
    strcpy(buffer, logLevelPrefixes[level]);
    
    // Format the message with the variable arguments
    va_list args;
    va_start(args, format);
    vsprintf(buffer + strlen(logLevelPrefixes[level]), format, args);
    va_end(args);
    
    // Send the message to the terminal
    SerialConsoleWriteString(buffer);
} 