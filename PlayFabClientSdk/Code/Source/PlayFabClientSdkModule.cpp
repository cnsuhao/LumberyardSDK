
#include "StdAfx.h"

#include <platform_impl.h> // Resharper says this is unused, but it's still required in some less direct way
#include "PlayFabClient_SettingsSysComponent.h"
#include "PlayFabClient_ClientSysComponent.h"
#include "PlayFabClient_AuthenticationSysComponent.h"
#include "PlayFabClient_CloudScriptSysComponent.h"
#include "PlayFabClient_DataSysComponent.h"
#include "PlayFabClient_GroupsSysComponent.h"
#include "PlayFabClient_ProfilesSysComponent.h"

#include "PlayFabSettings.h"
#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientApi.h>

#include <FlowSystem/Nodes/FlowBaseNode.h>
#include <IGem.h>

namespace PlayFabClientSdk
{
    static void ExampleGlobalErrorHandler(const PlayFabError& error, void* customData)
    {
        AZ_TracePrintf("PlayFab", "==================================================================");
        AZ_TracePrintf("PlayFab", "PlayFab Error");
        AZ_TracePrintf("PlayFab", " HTTP Status: %s", error.HttpStatus.c_str());
        AZ_TracePrintf("PlayFab", " Error: %s", error.ErrorName.c_str());
        AZ_TracePrintf("PlayFab", " Description: %s", error.ErrorMessage.c_str());

        if (!error.ErrorDetails.empty())
        {
            AZ_TracePrintf("PlayFab", " Additional Info:");
            for (auto& details : error.ErrorDetails)
            {
                AZ_TracePrintf("PlayFab", "  %s: %s", details.first.c_str(), details.second.c_str());
            }
        }
        AZ_TracePrintf("PlayFab", "==================================================================");
    }

    class PlayFabClientSdkModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabClientSdkModule, "{F73EAA98-BB00-45D4-832F-6001FF96D66E}", CryHooksModule);

        PlayFabClientSdkModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabClient_SettingsSysComponent::CreateDescriptor(),
                PlayFabClient_ClientSysComponent::CreateDescriptor(),
                PlayFabClient_AuthenticationSysComponent::CreateDescriptor(),
                PlayFabClient_CloudScriptSysComponent::CreateDescriptor(),
                PlayFabClient_DataSysComponent::CreateDescriptor(),
                PlayFabClient_GroupsSysComponent::CreateDescriptor(),
                PlayFabClient_ProfilesSysComponent::CreateDescriptor(),

            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabClient_SettingsSysComponent>(),
                azrtti_typeid<PlayFabClient_ClientSysComponent>(),
                azrtti_typeid<PlayFabClient_AuthenticationSysComponent>(),
                azrtti_typeid<PlayFabClient_CloudScriptSysComponent>(),
                azrtti_typeid<PlayFabClient_DataSysComponent>(),
                azrtti_typeid<PlayFabClient_GroupsSysComponent>(),
                azrtti_typeid<PlayFabClient_ProfilesSysComponent>(),

            };
        }

        void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override
        {
            switch (event)
            {
            case ESYSTEM_EVENT_FLOW_SYSTEM_REGISTER_EXTERNAL_NODES:
                RegisterExternalFlowNodes();
                break;
            case ESYSTEM_EVENT_GAME_POST_INIT:
            {
                // Initialise the settings
                PlayFabSettings::playFabSettings = new PlayFabSettings();
                // Start the http request manager thread
                PlayFabRequestManager::playFabHttp = new PlayFabRequestManager();

                // Set the game title id
                auto titleIdCvar = gEnv->pConsole->GetCVar("playfab_title_id");
                if (titleIdCvar)
                    PlayFabSettings::playFabSettings->titleId = titleIdCvar->GetString();

                // Set the server API secret key
                auto secretKeyCvar = gEnv->pConsole->GetCVar("playfab_secret_key");
                if (secretKeyCvar)
                    PlayFabSettings::playFabSettings->developerSecretKey = secretKeyCvar->GetString();

                // Set a default error handler
                PlayFabSettings::playFabSettings->globalErrorHandler = &ExampleGlobalErrorHandler;
            }
            break;

            case ESYSTEM_EVENT_FULL_SHUTDOWN:
            case ESYSTEM_EVENT_FAST_SHUTDOWN:
                // #THIRD_KIND_PLAYFAB_SHUTDOWN_FIXES: - Changed statics to pointers, so they can be deleted before the system allocator is destroyed.

                // Log out and clear the auth token
                PlayFabClientApi::ForgetAllCredentials();

                // Shut down the http handler thread
                SAFE_DELETE(PlayFabRequestManager::playFabHttp);

                // Destroy the settings
                SAFE_DELETE(PlayFabSettings::playFabSettings);

                break;
            }
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(PlayFabClientSdk_59aceeb4fcdc4556859a00fdef51702b, PlayFabClientSdk::PlayFabClientSdkModule)
