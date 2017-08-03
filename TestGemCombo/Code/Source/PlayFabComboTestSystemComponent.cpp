
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabComboTestSystemComponent.h"

#include <PlayFabComboSdk/PlayFabCombo_ClientBus.h>
#include <PlayFabComboSdk/PlayFabCombo_SettingsBus.h>
using namespace PlayFabComboSdk;

namespace PlayFabComboTest
{
    void PlayFabComboTestSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabComboTestSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabComboTestSystemComponent>("PlayFabComboTest", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabComboTestSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabComboTestService"));
    }

    void PlayFabComboTestSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabComboTestService"));
    }

    void PlayFabComboTestSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabComboTestSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabComboTestSystemComponent::Init()
    {
    }

    void PlayFabComboTestSystemComponent::Activate()
    {
        PlayFabComboTestRequestBus::Handler::BusConnect();

        LoginOrRegister();
    }

    void PlayFabComboTestSystemComponent::Deactivate()
    {
        PlayFabComboTestRequestBus::Handler::BusDisconnect();
    }

    void OnLoginOrRegister(const ClientModels::LoginResult& result, void* customData)
    {
        auto playFabId = result.PlayFabId;
    }
    void OnSharedError(const PlayFabError& error, void* customData)
    {
        auto playFabId = "failed to log in";
    }

    void PlayFabComboTestSystemComponent::LoginOrRegister()
    {

        PlayFabCombo_SettingsRequestBus::Broadcast(&PlayFabCombo_SettingsRequests::SetTitleId, AZStd::string("6195"));

        ClientModels::LoginWithCustomIDRequest request;
        request.CustomId = "GettingStartedGuide";
        request.CreateAccount = true;
        EBUS_EVENT(PlayFabCombo_ClientRequestBus, LoginWithCustomID, request, OnLoginOrRegister, OnSharedError, nullptr);

    }
}
