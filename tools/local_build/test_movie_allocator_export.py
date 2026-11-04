import hashlib
from pathlib import Path
import tempfile
import unittest

from export_kit import reviewed_movie_allocator


class MovieAllocatorExportTests(unittest.TestCase):
    def fixture(self, directory):
        build = Path(directory).resolve()
        vendor = build / "parallel-gs-source/Granite/vulkan/memory_allocator.cpp"
        vendor.parent.mkdir(parents=True)
        vendor.write_text("void import() {\n\t\t::CloseHandle(external->handle);\n}\n")
        source = build / "recomp/reo_movie_memory_allocator.cpp"
        source.parent.mkdir()
        source.write_text('#include "movie_runtime/import_receipt.h"\n' + vendor.read_text().replace(
            "::CloseHandle(external->handle);",
            "const bool reo_movie_handle_closed = ::CloseHandle(external->handle) != FALSE;\n"
            "\t\treo_movie_import::provider_closed(reinterpret_cast<uintptr_t>(external->handle), reo_movie_handle_closed);"))
        output = "recomp/CMakeFiles/reo_movie_allocator_native.dir/reo_movie_memory_allocator.cpp.obj"
        rows = [{"file": str(source), "command": "compiler /Foreo_movie_allocator_native.dir/output.obj", "output": output}]
        (build / "build.ninja").write_text("build recomp/reo_recomp_file2.exe: linker " + output + " | granite-vulkan.lib\n")
        return build, vendor, source, rows, hashlib.sha256(vendor.read_bytes()).hexdigest()

    def test_reviewed_provider_is_a_direct_link_object(self):
        with tempfile.TemporaryDirectory() as directory:
            build, vendor, source, rows, pin = self.fixture(directory)
            before = vendor.read_bytes()
            self.assertEqual(reviewed_movie_allocator(build, rows, "reo_recomp_file2", pin), (source, rows[0]))
            self.assertEqual(vendor.read_bytes(), before)

    def test_unreviewed_vendor_source_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            build, vendor, source, rows, pin = self.fixture(directory)
            vendor.write_text(vendor.read_text() + "// source changed\n")
            with self.assertRaisesRegex(ValueError, "pinned Granite"):
                reviewed_movie_allocator(build, rows, "reo_recomp_file2", pin)

    def test_missing_or_changed_receipt_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            build, vendor, source, rows, pin = self.fixture(directory)
            source.write_text(vendor.read_text())
            with self.assertRaisesRegex(ValueError, "source-preserving"):
                reviewed_movie_allocator(build, rows, "reo_recomp_file2", pin)

    def test_missing_or_duplicate_compilation_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            build, vendor, source, rows, pin = self.fixture(directory)
            for invalid in ([], rows + rows):
                with self.subTest(rows=len(invalid)), self.assertRaisesRegex(ValueError, "exactly one"):
                    reviewed_movie_allocator(build, invalid, "reo_recomp_file2", pin)

    def test_order_only_or_archive_linkage_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            build, vendor, source, rows, pin = self.fixture(directory)
            for separator in (" | ", " || "):
                (build / "build.ninja").write_text("build recomp/reo_recomp_file2.exe: linker granite-vulkan.lib" + separator + rows[0]["output"] + "\n")
                with self.subTest(separator=separator), self.assertRaisesRegex(ValueError, "direct executable"):
                    reviewed_movie_allocator(build, rows, "reo_recomp_file2", pin)


if __name__ == "__main__":
    unittest.main()
