#ifndef CONFIG_H
#define CONFIG_H

#include "../util/util.h"

/**
 * @brief Doorstop configuration
 */
typedef struct {
    /**
     * @brief Whether Doorstop is enabled (enables hooking methods and executing
     * target assembly).
     */
    bool_t enabled;

    /**
     * @brief Whether to redirect Unity output log.
     *
     * If enabled, Doorstop will append `-logFile` command line argument to
     * process command line arguments. This will force Unity to write output
     * logs to the game folder.
     */
    bool_t redirect_output_log;

    /**
     * @brief Path to a managed assembly to invoke.
     */
    char_t *target_assembly;

    /**
     * @brief Path to use as the main DLL search path. If enabled, this folder
     * takes precedence over the default Managed folder.
     */
    char_t *mono_dll_search_path_override;

    /**
     * @brief Whether to enable the mono debugger.
     */
    bool_t mono_debug_enabled;

    /**
     * @brief Whether to enable the debugger in suspended state.
     *
     * If enabled, the runtime will force the game to wait until a debugger is
     * connected.
     */
    bool_t mono_debug_suspend;

    /**
     * @brief Debug address to use for the mono debugger.
     */
    char_t *mono_debug_address;
} Config;

extern Config config;

/**
 * @brief Load configuration.
 */
extern void load_config();

/**
 * @brief Initialize default values for configuration.
 */
extern void init_config_defaults();

/**
 * @brief Clean up configuration.
 */
extern void cleanup_config();
#endif