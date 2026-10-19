#pragma once
namespace vu_specialized {
struct ProgramTable;
}
// Caller registers legacy first; all objects are borrowed immutable preboot state.
bool reoRegisterNativeGeometryPrograms(const vu_specialized::ProgramTable*) noexcept;
// Optional REO_HAVE_NATIVE_64E_RIGID_GEOMETRY requires its full-image legacy key.
// REO_VU_NATIVE_64E_GEOMETRY=0 selects the immutable prior-body table view; the
// master switches still clear all native programs. No64e mode2 entry exists.
