#pragma once

#include <PlayFabComboSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabComboSdk
{
    namespace ProfilesModels
    {
        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EffectTypeAllow: writer.String("Allow"); break;
            case EffectTypeDeny: writer.String("Deny"); break;

            }
        }

        inline EffectType readEffectTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EffectType>(obj.GetInt());

            static std::map<const char *, EffectType, PlayFabComboSdk::StringCompare> _EffectTypeMap;
            if (_EffectTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EffectTypeMap["Allow"] = EffectTypeAllow;
                _EffectTypeMap["Deny"] = EffectTypeDeny;

            }

            auto output = _EffectTypeMap.find(obj.GetString());
            if (output != _EffectTypeMap.end())
                return output->second;

            return EffectTypeAllow; // Basically critical fail
        }

        struct EntityDataObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            AZStd::string EscapedDataObject;
            AZStd::string ObjectName;

            EntityDataObject() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            EntityDataObject(const EntityDataObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            EntityDataObject(const rapidjson::Value& obj) : EntityDataObject()
            {
                readFromValue(obj);
            }

            ~EntityDataObject()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataObject.notNull()) {
                    writer.String("DataObject");
                    DataObject.writeJSON(writer);
                }
                if (EscapedDataObject.length() > 0) {
                    writer.String("EscapedDataObject");
                    writer.String(EscapedDataObject.c_str());
                }
                if (ObjectName.length() > 0) {
                    writer.String("ObjectName");
                    writer.String(ObjectName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
                if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
                const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
                if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

                return true;
            }
        };

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

            static std::map<const char *, EntityTypes, PlayFabComboSdk::StringCompare> _EntityTypesMap;
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

        struct EntityPermissionStatement : public PlayFabBaseModel
        {
            AZStd::string Action;
            AZStd::string Comment;
            MultitypeVar Condition;
            EffectType Effect;
            MultitypeVar Principal;
            AZStd::string Resource;

            EntityPermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                Comment(),
                Condition(),
                Effect(),
                Principal(),
                Resource()
            {}

            EntityPermissionStatement(const EntityPermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                Comment(src.Comment),
                Condition(src.Condition),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            EntityPermissionStatement(const rapidjson::Value& obj) : EntityPermissionStatement()
            {
                readFromValue(obj);
            }

            ~EntityPermissionStatement()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Action");
                writer.String(Action.c_str());
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                if (Condition.notNull()) {
                    writer.String("Condition");
                    Condition.writeJSON(writer);
                }
                writer.String("Effect");
                writeEffectTypeEnumJSON(Effect, writer);
                writer.String("Principal");
                Principal.writeJSON(writer);
                writer.String("Resource");
                writer.String(Resource.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Action_member = obj.FindMember("Action");
                if (Action_member != obj.MemberEnd() && !Action_member->value.IsNull()) Action = Action_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Condition_member = obj.FindMember("Condition");
                if (Condition_member != obj.MemberEnd() && !Condition_member->value.IsNull()) Condition = MultitypeVar(Condition_member->value);
                const Value::ConstMemberIterator Effect_member = obj.FindMember("Effect");
                if (Effect_member != obj.MemberEnd() && !Effect_member->value.IsNull()) Effect = readEffectTypeFromValue(Effect_member->value);
                const Value::ConstMemberIterator Principal_member = obj.FindMember("Principal");
                if (Principal_member != obj.MemberEnd() && !Principal_member->value.IsNull()) Principal = MultitypeVar(Principal_member->value);
                const Value::ConstMemberIterator Resource_member = obj.FindMember("Resource");
                if (Resource_member != obj.MemberEnd() && !Resource_member->value.IsNull()) Resource = Resource_member->value.GetString();

                return true;
            }
        };

        struct EntityProfileFileMetadata : public PlayFabBaseModel
        {
            AZStd::string Checksum;
            AZStd::string FileName;
            time_t LastModified;
            Int32 Size;

            EntityProfileFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            EntityProfileFileMetadata(const EntityProfileFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            EntityProfileFileMetadata(const rapidjson::Value& obj) : EntityProfileFileMetadata()
            {
                readFromValue(obj);
            }

            ~EntityProfileFileMetadata()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Checksum.length() > 0) {
                    writer.String("Checksum");
                    writer.String(Checksum.c_str());
                }
                if (FileName.length() > 0) {
                    writer.String("FileName");
                    writer.String(FileName.c_str());
                }
                writer.String("LastModified");
                writeDatetime(LastModified, writer);
                writer.String("Size");
                writer.Int(Size);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Checksum_member = obj.FindMember("Checksum");
                if (Checksum_member != obj.MemberEnd() && !Checksum_member->value.IsNull()) Checksum = Checksum_member->value.GetString();
                const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
                if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
                const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
                if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
                const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
                if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetInt();

                return true;
            }
        };

        struct EntityProfileBody : public PlayFabBaseModel
        {
            EntityKey* Entity;
            AZStd::string EntityChain;
            std::map<AZStd::string, EntityProfileFileMetadata> Files;
            AZStd::string Language;
            std::map<AZStd::string, EntityDataObject> Objects;
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                Entity(nullptr),
                EntityChain(),
                Files(),
                Language(),
                Objects(),
                Permissions(),
                VersionNumber(0)
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                EntityChain(src.EntityChain),
                Files(src.Files),
                Language(src.Language),
                Objects(src.Objects),
                Permissions(src.Permissions),
                VersionNumber(src.VersionNumber)
            {}

            EntityProfileBody(const rapidjson::Value& obj) : EntityProfileBody()
            {
                readFromValue(obj);
            }

            ~EntityProfileBody()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (EntityChain.length() > 0) {
                    writer.String("EntityChain");
                    writer.String(EntityChain.c_str());
                }
                if (!Files.empty()) {
                    writer.String("Files");
                    writer.StartObject();
                    for (auto iter = Files.begin(); iter != Files.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (Language.length() > 0) {
                    writer.String("Language");
                    writer.String(Language.c_str());
                }
                if (!Objects.empty()) {
                    writer.String("Objects");
                    writer.StartObject();
                    for (auto iter = Objects.begin(); iter != Objects.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("VersionNumber");
                writer.Int(VersionNumber);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EntityChain_member = obj.FindMember("EntityChain");
                if (EntityChain_member != obj.MemberEnd() && !EntityChain_member->value.IsNull()) EntityChain = EntityChain_member->value.GetString();
                const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
                if (Files_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Files_member->value.MemberBegin(); iter != Files_member->value.MemberEnd(); ++iter) {
                        Files[iter->name.GetString()] = EntityProfileFileMetadata(iter->value);
                    }
                }
                const Value::ConstMemberIterator Language_member = obj.FindMember("Language");
                if (Language_member != obj.MemberEnd() && !Language_member->value.IsNull()) Language = Language_member->value.GetString();
                const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
                if (Objects_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Objects_member->value.MemberBegin(); iter != Objects_member->value.MemberEnd(); ++iter) {
                        Objects[iter->name.GetString()] = EntityDataObject(iter->value);
                    }
                }
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VersionNumber_member = obj.FindMember("VersionNumber");
                if (VersionNumber_member != obj.MemberEnd() && !VersionNumber_member->value.IsNull()) VersionNumber = VersionNumber_member->value.GetInt();

                return true;
            }
        };

        struct GetEntityProfileRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            EntityKey Entity;

            GetEntityProfileRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entity()
            {}

            GetEntityProfileRequest(const GetEntityProfileRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entity(src.Entity)
            {}

            GetEntityProfileRequest(const rapidjson::Value& obj) : GetEntityProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityProfileRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataAsObject.notNull()) {
                    writer.String("DataAsObject");
                    writer.Bool(DataAsObject);
                }
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
                if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);

                return true;
            }
        };

        struct GetEntityProfileResponse : public PlayFabBaseModel
        {
            EntityProfileBody* Profile;

            GetEntityProfileResponse() :
                PlayFabBaseModel(),
                Profile(nullptr)
            {}

            GetEntityProfileResponse(const GetEntityProfileResponse& src) :
                PlayFabBaseModel(),
                Profile(src.Profile ? new EntityProfileBody(*src.Profile) : nullptr)
            {}

            GetEntityProfileResponse(const rapidjson::Value& obj) : GetEntityProfileResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityProfileResponse()
            {
                if (Profile != nullptr) delete Profile;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Profile != nullptr) {
                    writer.String("Profile");
                    Profile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new EntityProfileBody(Profile_member->value);

                return true;
            }
        };

        struct GetEntityProfilesRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            AZStd::vector<EntityKey> Entities; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetEntityProfilesRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entities()
            {}

            GetEntityProfilesRequest(const GetEntityProfilesRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entities(src.Entities)
            {}

            GetEntityProfilesRequest(const rapidjson::Value& obj) : GetEntityProfilesRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityProfilesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataAsObject.notNull()) {
                    writer.String("DataAsObject");
                    writer.Bool(DataAsObject);
                }
                writer.String("Entities");
                writer.StartArray();
                for (auto iter = Entities.begin(); iter != Entities.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
                if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
                const Value::ConstMemberIterator Entities_member = obj.FindMember("Entities");
                if (Entities_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Entities_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Entities.push_back(EntityKey(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetEntityProfilesResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityProfileBody> Profiles; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetEntityProfilesResponse() :
                PlayFabBaseModel(),
                Profiles()
            {}

            GetEntityProfilesResponse(const GetEntityProfilesResponse& src) :
                PlayFabBaseModel(),
                Profiles(src.Profiles)
            {}

            GetEntityProfilesResponse(const rapidjson::Value& obj) : GetEntityProfilesResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityProfilesResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Profiles.empty()) {
                    writer.String("Profiles");
                    writer.StartArray();
                    for (auto iter = Profiles.begin(); iter != Profiles.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Profiles_member = obj.FindMember("Profiles");
                if (Profiles_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Profiles_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Profiles.push_back(EntityProfileBody(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetGlobalPolicyRequest : public PlayFabBaseModel
        {

            GetGlobalPolicyRequest() :
                PlayFabBaseModel()
            {}

            GetGlobalPolicyRequest(const GetGlobalPolicyRequest& src) :
                PlayFabBaseModel()
            {}

            GetGlobalPolicyRequest(const rapidjson::Value& obj) : GetGlobalPolicyRequest()
            {
                readFromValue(obj);
            }

            ~GetGlobalPolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetGlobalPolicyResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetGlobalPolicyResponse() :
                PlayFabBaseModel(),
                Permissions()
            {}

            GetGlobalPolicyResponse(const GetGlobalPolicyResponse& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            GetGlobalPolicyResponse(const rapidjson::Value& obj) : GetGlobalPolicyResponse()
            {
                readFromValue(obj);
            }

            ~GetGlobalPolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case OperationTypesCreated: writer.String("Created"); break;
            case OperationTypesUpdated: writer.String("Updated"); break;
            case OperationTypesDeleted: writer.String("Deleted"); break;
            case OperationTypesNone: writer.String("None"); break;

            }
        }

        inline OperationTypes readOperationTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<OperationTypes>(obj.GetInt());

            static std::map<const char *, OperationTypes, PlayFabComboSdk::StringCompare> _OperationTypesMap;
            if (_OperationTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _OperationTypesMap["Created"] = OperationTypesCreated;
                _OperationTypesMap["Updated"] = OperationTypesUpdated;
                _OperationTypesMap["Deleted"] = OperationTypesDeleted;
                _OperationTypesMap["None"] = OperationTypesNone;

            }

            auto output = _OperationTypesMap.find(obj.GetString());
            if (output != _OperationTypesMap.end())
                return output->second;

            return OperationTypesCreated; // Basically critical fail
        }

        struct SetEntityProfilePolicyRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<EntityPermissionStatement> Statements; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetEntityProfilePolicyRequest() :
                PlayFabBaseModel(),
                Entity(),
                Statements()
            {}

            SetEntityProfilePolicyRequest(const SetEntityProfilePolicyRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Statements(src.Statements)
            {}

            SetEntityProfilePolicyRequest(const rapidjson::Value& obj) : SetEntityProfilePolicyRequest()
            {
                readFromValue(obj);
            }

            ~SetEntityProfilePolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                if (!Statements.empty()) {
                    writer.String("Statements");
                    writer.StartArray();
                    for (auto iter = Statements.begin(); iter != Statements.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Statements_member = obj.FindMember("Statements");
                if (Statements_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statements_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statements.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetEntityProfilePolicyResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetEntityProfilePolicyResponse() :
                PlayFabBaseModel(),
                Permissions()
            {}

            SetEntityProfilePolicyResponse(const SetEntityProfilePolicyResponse& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            SetEntityProfilePolicyResponse(const rapidjson::Value& obj) : SetEntityProfilePolicyResponse()
            {
                readFromValue(obj);
            }

            ~SetEntityProfilePolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetGlobalPolicyRequest : public PlayFabBaseModel
        {
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetGlobalPolicyRequest() :
                PlayFabBaseModel(),
                Permissions()
            {}

            SetGlobalPolicyRequest(const SetGlobalPolicyRequest& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            SetGlobalPolicyRequest(const rapidjson::Value& obj) : SetGlobalPolicyRequest()
            {
                readFromValue(obj);
            }

            ~SetGlobalPolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetGlobalPolicyResponse : public PlayFabBaseModel
        {

            SetGlobalPolicyResponse() :
                PlayFabBaseModel()
            {}

            SetGlobalPolicyResponse(const SetGlobalPolicyResponse& src) :
                PlayFabBaseModel()
            {}

            SetGlobalPolicyResponse(const rapidjson::Value& obj) : SetGlobalPolicyResponse()
            {
                readFromValue(obj);
            }

            ~SetGlobalPolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetProfileLanguageRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ExpectedVersion;
            AZStd::string Language;

            SetProfileLanguageRequest() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ExpectedVersion(0),
                Language()
            {}

            SetProfileLanguageRequest(const SetProfileLanguageRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ExpectedVersion(src.ExpectedVersion),
                Language(src.Language)
            {}

            SetProfileLanguageRequest(const rapidjson::Value& obj) : SetProfileLanguageRequest()
            {
                readFromValue(obj);
            }

            ~SetProfileLanguageRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("ExpectedVersion");
                writer.Int(ExpectedVersion);
                if (Language.length() > 0) {
                    writer.String("Language");
                    writer.String(Language.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ExpectedVersion_member = obj.FindMember("ExpectedVersion");
                if (ExpectedVersion_member != obj.MemberEnd() && !ExpectedVersion_member->value.IsNull()) ExpectedVersion = ExpectedVersion_member->value.GetInt();
                const Value::ConstMemberIterator Language_member = obj.FindMember("Language");
                if (Language_member != obj.MemberEnd() && !Language_member->value.IsNull()) Language = Language_member->value.GetString();

                return true;
            }
        };

        struct SetProfileLanguageResponse : public PlayFabBaseModel
        {
            Boxed<OperationTypes> OperationResult;
            OptionalInt32 VersionNumber;

            SetProfileLanguageResponse() :
                PlayFabBaseModel(),
                OperationResult(),
                VersionNumber()
            {}

            SetProfileLanguageResponse(const SetProfileLanguageResponse& src) :
                PlayFabBaseModel(),
                OperationResult(src.OperationResult),
                VersionNumber(src.VersionNumber)
            {}

            SetProfileLanguageResponse(const rapidjson::Value& obj) : SetProfileLanguageResponse()
            {
                readFromValue(obj);
            }

            ~SetProfileLanguageResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OperationResult.notNull()) {
                    writer.String("OperationResult");
                    writeOperationTypesEnumJSON(OperationResult, writer);
                }
                if (VersionNumber.notNull()) {
                    writer.String("VersionNumber");
                    writer.Int(VersionNumber);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OperationResult_member = obj.FindMember("OperationResult");
                if (OperationResult_member != obj.MemberEnd() && !OperationResult_member->value.IsNull()) OperationResult = readOperationTypesFromValue(OperationResult_member->value);
                const Value::ConstMemberIterator VersionNumber_member = obj.FindMember("VersionNumber");
                if (VersionNumber_member != obj.MemberEnd() && !VersionNumber_member->value.IsNull()) VersionNumber = VersionNumber_member->value.GetInt();

                return true;
            }
        };


    }
}
