/**
 * \file
 *
 * \brief Debug Logger Module Header
 *
 * This module provides functions for logging messages at different severity levels.
 */

#ifndef DEBUGLOGGER_H_
#define DEBUGLOGGER_H_

/**
 * \brief Debug log levels
 */
enum eDebugLogLevels {
    LOG_INFO_LVL    = 0, /**< Logs an INFO message */
    LOG_DEBUG_LVL   = 1, /**< Logs a DEBUG message */
    LOG_WARNING_LVL = 2, /**< Logs a WARNING message */
    LOG_ERROR_LVL   = 3, /**< Logs an ERROR message */
    LOG_FATAL_LVL   = 4, /**< Logs a FATAL message (non-recoverable error) */
    LOG_OFF_LVL     = 5, /**< Disables logging */
    N_DEBUG_LEVELS  = 6  /**< Maximum number of log levels */
};

/**
 * \brief Get the current log level
 *
 * \return Current log level
 */
enum eDebugLogLevels getLogLevel(void);

/**
 * \brief Set the log level
 *
 * Only messages with a level equal to or higher than this level will be printed.
 *
 * \param debugLevel The new log level
 */
void setLogLevel(enum eDebugLogLevels debugLevel);

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
void LogMessage(enum eDebugLogLevels level, const char *format, ...);

#endif /* DEBUGLOGGER_H_ */ 