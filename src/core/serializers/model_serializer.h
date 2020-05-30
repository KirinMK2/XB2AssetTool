#pragma once
#include <core.h>
#include <structs.h>
#include <serializers/base_serializer.h>

namespace xb2at {
namespace core {

	/**
	 * options to pass to modelSerializer::Serialize()
	 */
	struct modelSerializerOptions {

		/**
		 * Output format.
		 */
		enum class Format : byte {
			/**
			 * binary glTF format
			 */
			GLTFBinary,

			/**
			 * text glTF format
			 */
			 GLTFText,

			/**
			 * Raw dump format.
			 */
			Dump
		} OutputFormat;

		/**
		 * Output directory.
		 */
		const fs::path& outputDir;

		/**
		 * Output filename of the model.
		 */
		const std::string& filename;

		/**
		 * The level of detail at which we should export meshes.
		 */
		int32 lod;

		/**
		 * Save morphs to the model?
		 */
		bool saveMorphs;
	};

	/**
	 * Model serializer.
	 * Serializes model to a file.
	 */
	struct modelSerializer : public base_serializer {

		/**
		 * Serialize a mesh with the provided options,
		 *
		 * \param[in] meshesToDump The meshes to dump.
		 * \param[in] options Options.
		 */
		void Serialize(std::vector<mesh::mesh>& meshToDump, mxmd::mxmd& mxmdData, modelSerializerOptions& options);

	};
}
}