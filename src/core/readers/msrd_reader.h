#pragma once
#include <core.h>
#include <structs.h>
#include "base_reader.h"

namespace xb2at {
namespace core {

	/**
	 * Options to pass to msrdReader::Read().
	 */
	struct msrdReaderOptions {

		/**
		 * The output directory (where we should place files.)
		 */
		fs::path outputDirectory;

		/**
		 * Save decompressed XBC1 files to the output directory.
		 */
		bool saveDecompressedXbc1;

	};

	/**
	 * Reads MSRD files.
	 */
	struct msrdReader : public base_reader {

		msrdReader(std::istream& input_stream)
			: stream(input_stream) {
		
		}

		/**
		 * Read a MSRD file and output a structure.
		 *
		 * \param[in] opts Options to pass to the reader
		 */
		msrd::msrd Read(const msrdReaderOptions& opts);
		

	private:
		std::istream& stream;
	};


}
}