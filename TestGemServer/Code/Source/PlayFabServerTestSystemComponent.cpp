
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServerTestSystemComponent.h"

namespace PlayFabServerTest
{
    void PlayFabServerTestSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServerTestSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServerTestSystemComponent>("PlayFabServerTest", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServerTestSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServerTestService"));
    }

    void PlayFabServerTestSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServerTestService"));
    }

    void PlayFabServerTestSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServerTestSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServerTestSystemComponent::Init()
    {
    }

    void PlayFabServerTestSystemComponent::Activate()
    {
        PlayFabServerTestRequestBus::Handler::BusConnect();

        LoginOrRegister();
    }

    void PlayFabServerTestSystemComponent::Deactivate()
    {
        PlayFabServerTestRequestBus::Handler::BusDisconnect();
    }

    void PlayFabServerTestSystemComponent::LoginOrRegister()
    {

    }
}
