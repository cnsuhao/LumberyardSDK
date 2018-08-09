#pragma once

#include <PlayFabServerSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabServerSdk
{
    namespace EventsModels
    {
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
        };

        inline void writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EntityTypestitle: writer.String("title"); break;
            case EntityTypesmaster_player_account: writer.String("master_player_account"); break;
            case EntityTypestitle_player_account: writer.String("title_player_account"); break;
            case EntityTypescharacter: writer.String("character"); break;
            case EntityTypesgroup: writer.String("group"); break;
            case EntityTypesservice: writer.String("service"); break;

            }
        }

        inline EntityTypes readEntityTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EntityTypes>(obj.GetInt());

            static std::map<const char *, EntityTypes, PlayFabServerSdk::StringCompare> _EntityTypesMap;
            if (_EntityTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EntityTypesMap["title"] = EntityTypestitle;
                _EntityTypesMap["master_player_account"] = EntityTypesmaster_player_account;
                _EntityTypesMap["title_player_account"] = EntityTypestitle_player_account;
                _EntityTypesMap["character"] = EntityTypescharacter;
                _EntityTypesMap["group"] = EntityTypesgroup;
                _EntityTypesMap["service"] = EntityTypesservice;

            }

            auto output = _EntityTypesMap.find(obj.GetString());
            if (output != _EntityTypesMap.end())
                return output->second;

            return EntityTypestitle; // Basically critical fail
        }

        struct EntityKey : public PlayFabBaseModel
        {
            AZStd::string Id;
            Boxed<EntityTypes> Type;
            AZStd::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Id");
                writer.String(Id.c_str());
                if (Type.notNull()) {
                    writer.String("Type");
                    writeEntityTypesEnumJSON(Type, writer);
                }
                if (TypeString.length() > 0) {
                    writer.String("TypeString");
                    writer.String(TypeString.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
                if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readEntityTypesFromValue(Type_member->value);
                const Value::ConstMemberIterator TypeString_member = obj.FindMember("TypeString");
                if (TypeString_member != obj.MemberEnd() && !TypeString_member->value.IsNull()) TypeString = TypeString_member->value.GetString();

                return true;
            }
        };

        struct EventContents : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::string EventNamespace;
            AZStd::string Name;
            AZStd::string OriginalId;
            OptionalTime OriginalTimestamp;
            MultitypeVar Payload;
            AZStd::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
                Entity(),
                EventNamespace(),
                Name(),
                OriginalId(),
                OriginalTimestamp(),
                Payload(),
                PayloadJSON()
            {}

            EventContents(const EventContents& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EventNamespace(src.EventNamespace),
                Name(src.Name),
                OriginalId(src.OriginalId),
                OriginalTimestamp(src.OriginalTimestamp),
                Payload(src.Payload),
                PayloadJSON(src.PayloadJSON)
            {}

            EventContents(const rapidjson::Value& obj) : EventContents()
            {
                readFromValue(obj);
            }

            ~EventContents()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("EventNamespace");
                writer.String(EventNamespace.c_str());
                writer.String("Name");
                writer.String(Name.c_str());
                if (OriginalId.length() > 0) {
                    writer.String("OriginalId");
                    writer.String(OriginalId.c_str());
                }
                if (OriginalTimestamp.notNull()) {
                    writer.String("OriginalTimestamp");
                    writeDatetime(OriginalTimestamp, writer);
                }
                if (Payload.notNull()) {
                    writer.String("Payload");
                    Payload.writeJSON(writer);
                }
                if (PayloadJSON.length() > 0) {
                    writer.String("PayloadJSON");
                    writer.String(PayloadJSON.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EventNamespace_member = obj.FindMember("EventNamespace");
                if (EventNamespace_member != obj.MemberEnd() && !EventNamespace_member->value.IsNull()) EventNamespace = EventNamespace_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator OriginalId_member = obj.FindMember("OriginalId");
                if (OriginalId_member != obj.MemberEnd() && !OriginalId_member->value.IsNull()) OriginalId = OriginalId_member->value.GetString();
                const Value::ConstMemberIterator OriginalTimestamp_member = obj.FindMember("OriginalTimestamp");
                if (OriginalTimestamp_member != obj.MemberEnd() && !OriginalTimestamp_member->value.IsNull()) OriginalTimestamp = readDatetime(OriginalTimestamp_member->value);
                const Value::ConstMemberIterator Payload_member = obj.FindMember("Payload");
                if (Payload_member != obj.MemberEnd() && !Payload_member->value.IsNull()) Payload = MultitypeVar(Payload_member->value);
                const Value::ConstMemberIterator PayloadJSON_member = obj.FindMember("PayloadJSON");
                if (PayloadJSON_member != obj.MemberEnd() && !PayloadJSON_member->value.IsNull()) PayloadJSON = PayloadJSON_member->value.GetString();

                return true;
            }
        };

        struct WriteEventsRequest : public PlayFabBaseModel
        {
            AZStd::vector<EventContents> Events; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            WriteEventsRequest() :
                PlayFabBaseModel(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabBaseModel(),
                Events(src.Events)
            {}

            WriteEventsRequest(const rapidjson::Value& obj) : WriteEventsRequest()
            {
                readFromValue(obj);
            }

            ~WriteEventsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Events");
                writer.StartArray();
                for (auto iter = Events.begin(); iter != Events.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Events_member = obj.FindMember("Events");
                if (Events_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Events_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Events.push_back(EventContents(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct WriteEventsResponse : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> AssignedEventIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            WriteEventsResponse() :
                PlayFabBaseModel(),
                AssignedEventIds()
            {}

            WriteEventsResponse(const WriteEventsResponse& src) :
                PlayFabBaseModel(),
                AssignedEventIds(src.AssignedEventIds)
            {}

            WriteEventsResponse(const rapidjson::Value& obj) : WriteEventsResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!AssignedEventIds.empty()) {
                    writer.String("AssignedEventIds");
                    writer.StartArray();
                    for (auto iter = AssignedEventIds.begin(); iter != AssignedEventIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AssignedEventIds_member = obj.FindMember("AssignedEventIds");
                if (AssignedEventIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AssignedEventIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AssignedEventIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };


    }
}
