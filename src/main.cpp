#include "main.hpp"

#include "modloader/shared/modloader.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup
int TimesOfRan = 0;

// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
    
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = "sussybaka";
    info.version = "0.69";
    modInfo = info;
	
    getConfig().Load();
}

MAKE_HOOK_FIND_CLASS_INSTANCE(sus, "GorillaLocomotion", "Player", "Awake", void, Il2CppObject* self)
{
    sus(self);
    std::string baka = "playerRigidbody";
    auto sus = il2cpp_utils::GetFieldClass(il2cpp_functions::class_get_field_from_name(self->klass, baka.c_str()));
    il2cpp_utils::SetFieldValue(sus, "useGravity", false);
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();
    Logger& logger = getLogger();
    logger.info("Installing hooks...");
    //INSTALL_HOOK(debuglogger, GorillaStart);
    INSTALL_HOOK(logger, sus);
    logger.info("Installed all hooks!");
}