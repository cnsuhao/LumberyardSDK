
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClientTestSystemComponent.h"

#include <PlayFabClientSdk/PlayFabClient_ClientBus.h>
#include <PlayFabClientSdk/PlayFabClient_SettingsBus.h>
using namespace PlayFabClientSdk;

namespace PlayFabClientTest
{
    void PlayFabClientTestSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClientTestSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClientTestSystemComponent>("PlayFabClientTest", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClientTestSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClientTestService"));
    }

    void PlayFabClientTestSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClientTestService"));
    }

    void PlayFabClientTestSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClientTestSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClientTestSystemComponent::Init()
    {
    }

    void PlayFabClientTestSystemComponent::Activate()
    {
        PlayFabClientTestRequestBus::Handler::BusConnect();

        LoginOrRegister();
    }

    void PlayFabClientTestSystemComponent::Deactivate()
    {
        PlayFabClientTestRequestBus::Handler::BusDisconnect();
    }

    void OnLoginOrRegister(const ClientModels::LoginResult& result, void* customData)
    {
        auto playFabId = result.PlayFabId;
    }
    void OnSharedError(const PlayFabError& error, void* customData)
    {
        auto playFabId = "failed to log in";
    }

    void PlayFabClientTestSystemComponent::LoginOrRegister()
    {

        PlayFabClient_SettingsRequestBus::Broadcast(&PlayFabClient_SettingsRequests::SetTitleId, AZStd::string("6195"));

        ClientModels::LoginWithCustomIDRequest request;
        request.CustomId = "GettingStartedGuide";
        request.CreateAccount = true;
        EBUS_EVENT(PlayFabClient_ClientRequestBus, LoginWithCustomID, request, OnLoginOrRegister, OnSharedError, nullptr);

    }
}
