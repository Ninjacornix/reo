#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A830
// Address: 0x10a830 - 0x10a8c8
void sub_0010A830_0x10a830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A830_0x10a830");
#endif

    switch (ctx->pc) {
        case 0x10a8acu: goto label_10a8ac;
        default: break;
    }

    ctx->pc = 0x10a830u;

    // 0x10a830: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10a830u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10a834: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x10a834u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x10a838: 0x8c4d97f0  lw          $t5, -0x6810($v0)
    ctx->pc = 0x10a838u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10a83c: 0x24020208  addiu       $v0, $zero, 0x208
    ctx->pc = 0x10a83cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 520));
    // 0x10a840: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x10a840u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x10a844: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x10a844u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a848: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x10a848u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x10a84c: 0xffa60090  sd          $a2, 0x90($sp)
    ctx->pc = 0x10a84cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 6));
    // 0x10a850: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10a850u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a854: 0x27a60090  addiu       $a2, $sp, 0x90
    ctx->pc = 0x10a854u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x10a858: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x10a858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x10a85c: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x10a85cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x10a860: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x10a860u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x10a864: 0xffa70098  sd          $a3, 0x98($sp)
    ctx->pc = 0x10a864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 7));
    // 0x10a868: 0xffa800a0  sd          $t0, 0xA0($sp)
    ctx->pc = 0x10a868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 8));
    // 0x10a86c: 0xffa900a8  sd          $t1, 0xA8($sp)
    ctx->pc = 0x10a86cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 9));
    // 0x10a870: 0xffaa00b0  sd          $t2, 0xB0($sp)
    ctx->pc = 0x10a870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 10));
    // 0x10a874: 0xffab00b8  sd          $t3, 0xB8($sp)
    ctx->pc = 0x10a874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 11));
    // 0x10a878: 0xe7ac0070  swc1        $f12, 0x70($sp)
    ctx->pc = 0x10a878u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x10a87c: 0xe7ad0074  swc1        $f13, 0x74($sp)
    ctx->pc = 0x10a87cu;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x10a880: 0xe7ae0078  swc1        $f14, 0x78($sp)
    ctx->pc = 0x10a880u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    // 0x10a884: 0xe7af007c  swc1        $f15, 0x7C($sp)
    ctx->pc = 0x10a884u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 124), bits); }
    // 0x10a888: 0xe7b00080  swc1        $f16, 0x80($sp)
    ctx->pc = 0x10a888u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x10a88c: 0xe7b10084  swc1        $f17, 0x84($sp)
    ctx->pc = 0x10a88cu;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 132), bits); }
    // 0x10a890: 0xe7b20088  swc1        $f18, 0x88($sp)
    ctx->pc = 0x10a890u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x10a894: 0xe7b3008c  swc1        $f19, 0x8C($sp)
    ctx->pc = 0x10a894u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 140), bits); }
    // 0x10a898: 0xa7a2000c  sh          $v0, 0xC($sp)
    ctx->pc = 0x10a898u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10a89c: 0xafac0010  sw          $t4, 0x10($sp)
    ctx->pc = 0x10a89cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 12));
    // 0x10a8a0: 0xafad0054  sw          $t5, 0x54($sp)
    ctx->pc = 0x10a8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 13));
    // 0x10a8a4: 0xc04345a  jal         func_10D168
    ctx->pc = 0x10A8A4u;
    SET_GPR_U32(ctx, 31, 0x10A8ACu);
    ctx->pc = 0x10A8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A8A4u;
            // 0x10a8a8: 0xafac0000  sw          $t4, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A8ACu; }
        if (ctx->pc != 0x10A8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A8ACu; }
        if (ctx->pc != 0x10A8ACu) { return; }
    }
    ctx->pc = 0x10A8ACu;
label_10a8ac:
    // 0x10a8ac: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x10a8acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a8b0: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x10a8b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10a8b4: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x10a8b4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x10a8b8: 0x3e00008  jr          $ra
    ctx->pc = 0x10A8B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A8B8u;
            // 0x10a8bc: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A8ACu: goto label_10a8ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A8C0u;
    // 0x10a8c0: 0x3e00008  jr          $ra
    ctx->pc = 0x10A8C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A8C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A8C0u;
            // 0x10a8c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A8ACu: goto label_10a8ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A8C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
