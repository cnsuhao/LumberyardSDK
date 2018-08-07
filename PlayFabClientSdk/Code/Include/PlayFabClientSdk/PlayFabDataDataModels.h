#pragma once

#include <PlayFabClientSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabClientSdk
{
    namespace DataModels
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

            static std::map<const char *, EntityTypes, PlayFabClientSdk::StringCompare> _EntityTypesMap;
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

        struct AbortFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalInt32 ProfileVersion;

            AbortFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            AbortFileUploadsRequest(const AbortFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsRequest(const rapidjson::Value& obj) : AbortFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                if (ProfileVersion.notNull()) {
                    writer.String("ProfileVersion");
                    writer.Int(ProfileVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct AbortFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            AbortFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ProfileVersion(0)
            {}

            AbortFileUploadsResponse(const AbortFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsResponse(const rapidjson::Value& obj) : AbortFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsResponse()
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
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct DeleteFilesRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalInt32 ProfileVersion;

            DeleteFilesRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            DeleteFilesRequest(const DeleteFilesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesRequest(const rapidjson::Value& obj) : DeleteFilesRequest()
            {
                readFromValue(obj);
            }

            ~DeleteFilesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                if (ProfileVersion.notNull()) {
                    writer.String("ProfileVersion");
                    writer.Int(ProfileVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct DeleteFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            DeleteFilesResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ProfileVersion(0)
            {}

            DeleteFilesResponse(const DeleteFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesResponse(const rapidjson::Value& obj) : DeleteFilesResponse()
            {
                readFromValue(obj);
            }

            ~DeleteFilesResponse()
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
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct FinalizeFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            FinalizeFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames()
            {}

            FinalizeFileUploadsRequest(const FinalizeFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames)
            {}

            FinalizeFileUploadsRequest(const rapidjson::Value& obj) : FinalizeFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetFileMetadata : public PlayFabBaseModel
        {
            AZStd::string Checksum;
            AZStd::string DownloadUrl;
            AZStd::string FileName;
            time_t LastModified;
            Int32 Size;

            GetFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                DownloadUrl(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            GetFileMetadata(const GetFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                DownloadUrl(src.DownloadUrl),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            GetFileMetadata(const rapidjson::Value& obj) : GetFileMetadata()
            {
                readFromValue(obj);
            }

            ~GetFileMetadata()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Checksum.length() > 0) {
                    writer.String("Checksum");
                    writer.String(Checksum.c_str());
                }
                if (DownloadUrl.length() > 0) {
                    writer.String("DownloadUrl");
                    writer.String(DownloadUrl.c_str());
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
                const Value::ConstMemberIterator DownloadUrl_member = obj.FindMember("DownloadUrl");
                if (DownloadUrl_member != obj.MemberEnd() && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();
                const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
                if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
                const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
                if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
                const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
                if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetInt();

                return true;
            }
        };

        struct FinalizeFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<AZStd::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            FinalizeFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Metadata(),
                ProfileVersion(0)
            {}

            FinalizeFileUploadsResponse(const FinalizeFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            FinalizeFileUploadsResponse(const rapidjson::Value& obj) : FinalizeFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsResponse()
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
                if (!Metadata.empty()) {
                    writer.String("Metadata");
                    writer.StartObject();
                    for (auto iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
                if (Metadata_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
                        Metadata[iter->name.GetString()] = GetFileMetadata(iter->value);
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct GetFilesRequest : public PlayFabBaseModel
        {
            EntityKey Entity;

            GetFilesRequest() :
                PlayFabBaseModel(),
                Entity()
            {}

            GetFilesRequest(const GetFilesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity)
            {}

            GetFilesRequest(const rapidjson::Value& obj) : GetFilesRequest()
            {
                readFromValue(obj);
            }

            ~GetFilesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);

                return true;
            }
        };

        struct GetFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<AZStd::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            GetFilesResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Metadata(),
                ProfileVersion(0)
            {}

            GetFilesResponse(const GetFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            GetFilesResponse(const rapidjson::Value& obj) : GetFilesResponse()
            {
                readFromValue(obj);
            }

            ~GetFilesResponse()
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
                if (!Metadata.empty()) {
                    writer.String("Metadata");
                    writer.StartObject();
                    for (auto iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
                if (Metadata_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
                        Metadata[iter->name.GetString()] = GetFileMetadata(iter->value);
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct GetObjectsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            OptionalBool EscapeObject;

            GetObjectsRequest() :
                PlayFabBaseModel(),
                Entity(),
                EscapeObject()
            {}

            GetObjectsRequest(const GetObjectsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EscapeObject(src.EscapeObject)
            {}

            GetObjectsRequest(const rapidjson::Value& obj) : GetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~GetObjectsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                if (EscapeObject.notNull()) {
                    writer.String("EscapeObject");
                    writer.Bool(EscapeObject);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EscapeObject_member = obj.FindMember("EscapeObject");
                if (EscapeObject_member != obj.MemberEnd() && !EscapeObject_member->value.IsNull()) EscapeObject = EscapeObject_member->value.GetBool();

                return true;
            }
        };

        struct ObjectResult : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            AZStd::string EscapedDataObject;
            AZStd::string ObjectName;

            ObjectResult() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            ObjectResult(const ObjectResult& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ObjectResult(const rapidjson::Value& obj) : ObjectResult()
            {
                readFromValue(obj);
            }

            ~ObjectResult()
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

        struct GetObjectsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<AZStd::string, ObjectResult> Objects;
            Int32 ProfileVersion;

            GetObjectsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Objects(),
                ProfileVersion(0)
            {}

            GetObjectsResponse(const GetObjectsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Objects(src.Objects),
                ProfileVersion(src.ProfileVersion)
            {}

            GetObjectsResponse(const rapidjson::Value& obj) : GetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~GetObjectsResponse()
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
                if (!Objects.empty()) {
                    writer.String("Objects");
                    writer.StartObject();
                    for (auto iter = Objects.begin(); iter != Objects.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
                if (Objects_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Objects_member->value.MemberBegin(); iter != Objects_member->value.MemberEnd(); ++iter) {
                        Objects[iter->name.GetString()] = ObjectResult(iter->value);
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct InitiateFileUploadMetadata : public PlayFabBaseModel
        {
            AZStd::string FileName;
            AZStd::string UploadUrl;

            InitiateFileUploadMetadata() :
                PlayFabBaseModel(),
                FileName(),
                UploadUrl()
            {}

            InitiateFileUploadMetadata(const InitiateFileUploadMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                UploadUrl(src.UploadUrl)
            {}

            InitiateFileUploadMetadata(const rapidjson::Value& obj) : InitiateFileUploadMetadata()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadMetadata()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (FileName.length() > 0) {
                    writer.String("FileName");
                    writer.String(FileName.c_str());
                }
                if (UploadUrl.length() > 0) {
                    writer.String("UploadUrl");
                    writer.String(UploadUrl.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
                if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
                const Value::ConstMemberIterator UploadUrl_member = obj.FindMember("UploadUrl");
                if (UploadUrl_member != obj.MemberEnd() && !UploadUrl_member->value.IsNull()) UploadUrl = UploadUrl_member->value.GetString();

                return true;
            }
        };

        struct InitiateFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalInt32 ProfileVersion;

            InitiateFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            InitiateFileUploadsRequest(const InitiateFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            InitiateFileUploadsRequest(const rapidjson::Value& obj) : InitiateFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                if (ProfileVersion.notNull()) {
                    writer.String("ProfileVersion");
                    writer.Int(ProfileVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct InitiateFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;
            AZStd::vector<InitiateFileUploadMetadata> UploadDetails; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            InitiateFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ProfileVersion(0),
                UploadDetails()
            {}

            InitiateFileUploadsResponse(const InitiateFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ProfileVersion(src.ProfileVersion),
                UploadDetails(src.UploadDetails)
            {}

            InitiateFileUploadsResponse(const rapidjson::Value& obj) : InitiateFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsResponse()
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
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!UploadDetails.empty()) {
                    writer.String("UploadDetails");
                    writer.StartArray();
                    for (auto iter = UploadDetails.begin(); iter != UploadDetails.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator UploadDetails_member = obj.FindMember("UploadDetails");
                if (UploadDetails_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UploadDetails_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UploadDetails.push_back(InitiateFileUploadMetadata(memberList[i]));
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

            static std::map<const char *, OperationTypes, PlayFabClientSdk::StringCompare> _OperationTypesMap;
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

        struct SetObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            OptionalBool DeleteObject;
            AZStd::string EscapedDataObject;
            AZStd::string ObjectName;

            SetObject() :
                PlayFabBaseModel(),
                DataObject(),
                DeleteObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            SetObject(const SetObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                DeleteObject(src.DeleteObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            SetObject(const rapidjson::Value& obj) : SetObject()
            {
                readFromValue(obj);
            }

            ~SetObject()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataObject.notNull()) {
                    writer.String("DataObject");
                    DataObject.writeJSON(writer);
                }
                if (DeleteObject.notNull()) {
                    writer.String("DeleteObject");
                    writer.Bool(DeleteObject);
                }
                if (EscapedDataObject.length() > 0) {
                    writer.String("EscapedDataObject");
                    writer.String(EscapedDataObject.c_str());
                }
                writer.String("ObjectName");
                writer.String(ObjectName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
                if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
                const Value::ConstMemberIterator DeleteObject_member = obj.FindMember("DeleteObject");
                if (DeleteObject_member != obj.MemberEnd() && !DeleteObject_member->value.IsNull()) DeleteObject = DeleteObject_member->value.GetBool();
                const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
                if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

                return true;
            }
        };

        struct SetObjectInfo : public PlayFabBaseModel
        {
            AZStd::string ObjectName;
            AZStd::string OperationReason;
            Boxed<OperationTypes> SetResult;

            SetObjectInfo() :
                PlayFabBaseModel(),
                ObjectName(),
                OperationReason(),
                SetResult()
            {}

            SetObjectInfo(const SetObjectInfo& src) :
                PlayFabBaseModel(),
                ObjectName(src.ObjectName),
                OperationReason(src.OperationReason),
                SetResult(src.SetResult)
            {}

            SetObjectInfo(const rapidjson::Value& obj) : SetObjectInfo()
            {
                readFromValue(obj);
            }

            ~SetObjectInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ObjectName.length() > 0) {
                    writer.String("ObjectName");
                    writer.String(ObjectName.c_str());
                }
                if (OperationReason.length() > 0) {
                    writer.String("OperationReason");
                    writer.String(OperationReason.c_str());
                }
                if (SetResult.notNull()) {
                    writer.String("SetResult");
                    writeOperationTypesEnumJSON(SetResult, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();
                const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
                if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
                const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
                if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

                return true;
            }
        };

        struct SetObjectsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            OptionalInt32 ExpectedProfileVersion;
            AZStd::vector<SetObject> Objects; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetObjectsRequest() :
                PlayFabBaseModel(),
                Entity(),
                ExpectedProfileVersion(),
                Objects()
            {}

            SetObjectsRequest(const SetObjectsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Objects(src.Objects)
            {}

            SetObjectsRequest(const rapidjson::Value& obj) : SetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~SetObjectsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                if (ExpectedProfileVersion.notNull()) {
                    writer.String("ExpectedProfileVersion");
                    writer.Int(ExpectedProfileVersion);
                }
                writer.String("Objects");
                writer.StartArray();
                for (auto iter = Objects.begin(); iter != Objects.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
                if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
                if (Objects_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Objects_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Objects.push_back(SetObject(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetObjectsResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            AZStd::vector<SetObjectInfo> SetResults; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetObjectsResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                SetResults()
            {}

            SetObjectsResponse(const SetObjectsResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                SetResults(src.SetResults)
            {}

            SetObjectsResponse(const rapidjson::Value& obj) : SetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~SetObjectsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!SetResults.empty()) {
                    writer.String("SetResults");
                    writer.StartArray();
                    for (auto iter = SetResults.begin(); iter != SetResults.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator SetResults_member = obj.FindMember("SetResults");
                if (SetResults_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = SetResults_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        SetResults.push_back(SetObjectInfo(memberList[i]));
                    }
                }

                return true;
            }
        };


    }
}
