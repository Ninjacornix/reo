#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A8C8
// Address: 0x10a8c8 - 0x10aae0
void sub_0010A8C8_0x10a8c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A8C8_0x10a8c8");
#endif

    switch (ctx->pc) {
        case 0x10a928u: goto label_10a928;
        case 0x10a960u: goto label_10a960;
        case 0x10a994u: goto label_10a994;
        case 0x10aa18u: goto label_10aa18;
        case 0x10aa38u: goto label_10aa38;
        case 0x10aa7cu: goto label_10aa7c;
        default: break;
    }

    ctx->pc = 0x10a8c8u;

    // 0x10a8c8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x10a8c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x10a8cc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x10a8ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a8d0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x10a8d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x10a8d4: 0xffb00060  sd          $s0, 0x60($sp)
    ctx->pc = 0x10a8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 16));
    // 0x10a8d8: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x10a8d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x10a8dc: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x10a8dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a8e0: 0xffa60090  sd          $a2, 0x90($sp)
    ctx->pc = 0x10a8e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 6));
    // 0x10a8e4: 0xffa70098  sd          $a3, 0x98($sp)
    ctx->pc = 0x10a8e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 7));
    // 0x10a8e8: 0xa7a3000c  sh          $v1, 0xC($sp)
    ctx->pc = 0x10a8e8u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x10a8ec: 0xffa800a0  sd          $t0, 0xA0($sp)
    ctx->pc = 0x10a8ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 8));
    // 0x10a8f0: 0xffa900a8  sd          $t1, 0xA8($sp)
    ctx->pc = 0x10a8f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 9));
    // 0x10a8f4: 0xffaa00b0  sd          $t2, 0xB0($sp)
    ctx->pc = 0x10a8f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 10));
    // 0x10a8f8: 0xffab00b8  sd          $t3, 0xB8($sp)
    ctx->pc = 0x10a8f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 11));
    // 0x10a8fc: 0xe7ac0070  swc1        $f12, 0x70($sp)
    ctx->pc = 0x10a8fcu;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x10a900: 0xe7ad0074  swc1        $f13, 0x74($sp)
    ctx->pc = 0x10a900u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x10a904: 0xe7ae0078  swc1        $f14, 0x78($sp)
    ctx->pc = 0x10a904u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    // 0x10a908: 0xe7af007c  swc1        $f15, 0x7C($sp)
    ctx->pc = 0x10a908u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 124), bits); }
    // 0x10a90c: 0xe7b00080  swc1        $f16, 0x80($sp)
    ctx->pc = 0x10a90cu;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x10a910: 0xe7b10084  swc1        $f17, 0x84($sp)
    ctx->pc = 0x10a910u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 132), bits); }
    // 0x10a914: 0xe7b20088  swc1        $f18, 0x88($sp)
    ctx->pc = 0x10a914u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x10a918: 0xe7b3008c  swc1        $f19, 0x8C($sp)
    ctx->pc = 0x10a918u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 140), bits); }
    // 0x10a91c: 0xafa20010  sw          $v0, 0x10($sp)
    ctx->pc = 0x10a91cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x10a920: 0xc042c56  jal         func_10B158
    ctx->pc = 0x10A920u;
    SET_GPR_U32(ctx, 31, 0x10A928u);
    ctx->pc = 0x10A924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A920u;
            // 0x10a924: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A928u; }
        if (ctx->pc != 0x10A928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A928u; }
        if (ctx->pc != 0x10A928u) { return; }
    }
    ctx->pc = 0x10A928u;
label_10a928:
    // 0x10a928: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x10a928u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x10a92c: 0x3c030011  lui         $v1, 0x11
    ctx->pc = 0x10a92cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17 << 16));
    // 0x10a930: 0x8c8797f0  lw          $a3, -0x6810($a0)
    ctx->pc = 0x10a930u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294940656)));
    // 0x10a934: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10a934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a938: 0x2463a8c0  addiu       $v1, $v1, -0x5740
    ctx->pc = 0x10a938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944960));
    // 0x10a93c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10a93cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a940: 0x27a60090  addiu       $a2, $sp, 0x90
    ctx->pc = 0x10a940u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x10a944: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10a944u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x10a948: 0xafa30020  sw          $v1, 0x20($sp)
    ctx->pc = 0x10a948u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    // 0x10a94c: 0xafa70054  sw          $a3, 0x54($sp)
    ctx->pc = 0x10a94cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 7));
    // 0x10a950: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x10a950u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x10a954: 0xafa00030  sw          $zero, 0x30($sp)
    ctx->pc = 0x10a954u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 0));
    // 0x10a958: 0xc043abc  jal         func_10EAF0
    ctx->pc = 0x10A958u;
    SET_GPR_U32(ctx, 31, 0x10A960u);
    ctx->pc = 0x10A95Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A958u;
            // 0x10a95c: 0xafa00044  sw          $zero, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10EAF0u;
    if (runtime->hasFunction(0x10EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x10EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A960u; }
        if (ctx->pc != 0x10A960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010EAF0_0x10eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A960u; }
        if (ctx->pc != 0x10A960u) { return; }
    }
    ctx->pc = 0x10A960u;
label_10a960:
    // 0x10a960: 0xdfb00060  ld          $s0, 0x60($sp)
    ctx->pc = 0x10a960u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10a964: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x10a964u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x10a968: 0x3e00008  jr          $ra
    ctx->pc = 0x10A968u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A968u;
            // 0x10a96c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A928u: goto label_10a928;
            case 0x10A960u: goto label_10a960;
            case 0x10A994u: goto label_10a994;
            case 0x10A9B8u: goto label_10a9b8;
            case 0x10A9C4u: goto label_10a9c4;
            case 0x10AA18u: goto label_10aa18;
            case 0x10AA38u: goto label_10aa38;
            case 0x10AA7Cu: goto label_10aa7c;
            case 0x10AAA0u: goto label_10aaa0;
            case 0x10AAA8u: goto label_10aaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A970u;
    // 0x10a970: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a974: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x10a974u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a978: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a97c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a97cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a980: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10a980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10a984: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x10a984u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a988: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10a988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10a98c: 0xc04266c  jal         func_1099B0
    ctx->pc = 0x10A98Cu;
    SET_GPR_U32(ctx, 31, 0x10A994u);
    ctx->pc = 0x10A990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A98Cu;
            // 0x10a990: 0x8605000e  lh          $a1, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1099B0u;
    if (runtime->hasFunction(0x1099B0u)) {
        auto targetFn = runtime->lookupFunction(0x1099B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A994u; }
        if (ctx->pc != 0x10A994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001099B0_0x1099b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A994u; }
        if (ctx->pc != 0x10A994u) { return; }
    }
    ctx->pc = 0x10A994u;
label_10a994:
    // 0x10a994: 0x2203c  dsll32      $a0, $v0, 0
    ctx->pc = 0x10a994u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10a998: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x10a998u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x10a99c: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A99Cu;
    {
        const bool branch_taken_0x10a99c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x10A9A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A99Cu;
            // 0x10a9a0: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a99c) {
            ctx->pc = 0x10A9B8u;
            goto label_10a9b8;
        }
    }
    ctx->pc = 0x10A9A4u;
    // 0x10a9a4: 0x8e030050  lw          $v1, 0x50($s0)
    ctx->pc = 0x10a9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x10a9a8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x10a9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10a9ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10A9ACu;
    {
        const bool branch_taken_0x10a9ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A9B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A9ACu;
            // 0x10a9b0: 0xae030050  sw          $v1, 0x50($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a9ac) {
            ctx->pc = 0x10A9C4u;
            goto label_10a9c4;
        }
    }
    ctx->pc = 0x10A9B4u;
    // 0x10a9b4: 0x0  nop
    ctx->pc = 0x10a9b4u;
    // NOP
label_10a9b8:
    // 0x10a9b8: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x10a9b8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10a9bc: 0x3063efff  andi        $v1, $v1, 0xEFFF
    ctx->pc = 0x10a9bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61439);
    // 0x10a9c0: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x10a9c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
label_10a9c4:
    // 0x10a9c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a9c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a9c8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10a9c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a9cc: 0x3e00008  jr          $ra
    ctx->pc = 0x10A9CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A9CCu;
            // 0x10a9d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A928u: goto label_10a928;
            case 0x10A960u: goto label_10a960;
            case 0x10A994u: goto label_10a994;
            case 0x10A9B8u: goto label_10a9b8;
            case 0x10A9C4u: goto label_10a9c4;
            case 0x10AA18u: goto label_10aa18;
            case 0x10AA38u: goto label_10aa38;
            case 0x10AA7Cu: goto label_10aa7c;
            case 0x10AAA0u: goto label_10aaa0;
            case 0x10AAA8u: goto label_10aaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A9D4u;
    // 0x10a9d4: 0x0  nop
    ctx->pc = 0x10a9d4u;
    // NOP
    // 0x10a9d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a9d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a9dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a9dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a9e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a9e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a9e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a9e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a9e8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x10a9e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a9ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10a9ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x10a9f0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x10a9f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a9f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x10a9f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x10a9f8: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10a9f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10a9fc: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x10a9fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x10aa00: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10AA00u;
    {
        const bool branch_taken_0x10aa00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AA04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA00u;
            // 0x10aa04: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aa00) {
            ctx->pc = 0x10AA18u;
            goto label_10aa18;
        }
    }
    ctx->pc = 0x10AA08u;
    // 0x10aa08: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10aa08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10aa0c: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x10aa0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10aa10: 0xc041abe  jal         func_106AF8
    ctx->pc = 0x10AA10u;
    SET_GPR_U32(ctx, 31, 0x10AA18u);
    ctx->pc = 0x10AA14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA10u;
            // 0x10aa14: 0x8605000e  lh          $a1, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106AF8u;
    if (runtime->hasFunction(0x106AF8u)) {
        auto targetFn = runtime->lookupFunction(0x106AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA18u; }
        if (ctx->pc != 0x10AA18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106AF8_0x106af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA18u; }
        if (ctx->pc != 0x10AA18u) { return; }
    }
    ctx->pc = 0x10AA18u;
label_10aa18:
    // 0x10aa18: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10aa18u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10aa1c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10aa1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa20: 0x8605000e  lh          $a1, 0xE($s0)
    ctx->pc = 0x10aa20u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x10aa24: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x10aa24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa28: 0x3042efff  andi        $v0, $v0, 0xEFFF
    ctx->pc = 0x10aa28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)61439);
    // 0x10aa2c: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10aa2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10aa30: 0xc043e4c  jal         func_10F930
    ctx->pc = 0x10AA30u;
    SET_GPR_U32(ctx, 31, 0x10AA38u);
    ctx->pc = 0x10AA34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA30u;
            // 0x10aa34: 0xa602000c  sh          $v0, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F930u;
    if (runtime->hasFunction(0x10F930u)) {
        auto targetFn = runtime->lookupFunction(0x10F930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA38u; }
        if (ctx->pc != 0x10AA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F930_0x10f930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA38u; }
        if (ctx->pc != 0x10AA38u) { return; }
    }
    ctx->pc = 0x10AA38u;
label_10aa38:
    // 0x10aa38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10aa38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10aa3c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10aa3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10aa40: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10aa40u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10aa44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10aa44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10aa48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x10aa48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10aa4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x10aa4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10aa50: 0x3e00008  jr          $ra
    ctx->pc = 0x10AA50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10AA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA50u;
            // 0x10aa54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A928u: goto label_10a928;
            case 0x10A960u: goto label_10a960;
            case 0x10A994u: goto label_10a994;
            case 0x10A9B8u: goto label_10a9b8;
            case 0x10A9C4u: goto label_10a9c4;
            case 0x10AA18u: goto label_10aa18;
            case 0x10AA38u: goto label_10aa38;
            case 0x10AA7Cu: goto label_10aa7c;
            case 0x10AAA0u: goto label_10aaa0;
            case 0x10AAA8u: goto label_10aaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10AA58u;
    // 0x10aa58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10aa58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10aa5c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x10aa5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa60: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10aa60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10aa64: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10aa64u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa68: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10aa68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10aa6c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x10aa6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa70: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10aa70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10aa74: 0xc041abe  jal         func_106AF8
    ctx->pc = 0x10AA74u;
    SET_GPR_U32(ctx, 31, 0x10AA7Cu);
    ctx->pc = 0x10AA78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA74u;
            // 0x10aa78: 0x8605000e  lh          $a1, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106AF8u;
    if (runtime->hasFunction(0x106AF8u)) {
        auto targetFn = runtime->lookupFunction(0x106AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA7Cu; }
        if (ctx->pc != 0x10AA7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106AF8_0x106af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA7Cu; }
        if (ctx->pc != 0x10AA7Cu) { return; }
    }
    ctx->pc = 0x10AA7Cu;
label_10aa7c:
    // 0x10aa7c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10aa7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10aa80: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10aa80u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa84: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x10aa84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10aa88: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x10aa88u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x10aa8c: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10AA8Cu;
    {
        const bool branch_taken_0x10aa8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x10AA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA8Cu;
            // 0x10aa90: 0x9603000c  lhu         $v1, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aa8c) {
            ctx->pc = 0x10AAA0u;
            goto label_10aaa0;
        }
    }
    ctx->pc = 0x10AA94u;
    // 0x10aa94: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10AA94u;
    {
        const bool branch_taken_0x10aa94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA94u;
            // 0x10aa98: 0x3063efff  andi        $v1, $v1, 0xEFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61439);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aa94) {
            ctx->pc = 0x10AAA8u;
            goto label_10aaa8;
        }
    }
    ctx->pc = 0x10AA9Cu;
    // 0x10aa9c: 0x0  nop
    ctx->pc = 0x10aa9cu;
    // NOP
label_10aaa0:
    // 0x10aaa0: 0xae050050  sw          $a1, 0x50($s0)
    ctx->pc = 0x10aaa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 5));
    // 0x10aaa4: 0x34631000  ori         $v1, $v1, 0x1000
    ctx->pc = 0x10aaa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4096);
label_10aaa8:
    // 0x10aaa8: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x10aaa8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x10aaac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10aaacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10aab0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10aab0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10aab4: 0x3e00008  jr          $ra
    ctx->pc = 0x10AAB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10AAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AAB4u;
            // 0x10aab8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A928u: goto label_10a928;
            case 0x10A960u: goto label_10a960;
            case 0x10A994u: goto label_10a994;
            case 0x10A9B8u: goto label_10a9b8;
            case 0x10A9C4u: goto label_10a9c4;
            case 0x10AA18u: goto label_10aa18;
            case 0x10AA38u: goto label_10aa38;
            case 0x10AA7Cu: goto label_10aa7c;
            case 0x10AAA0u: goto label_10aaa0;
            case 0x10AAA8u: goto label_10aaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10AABCu;
    // 0x10aabc: 0x0  nop
    ctx->pc = 0x10aabcu;
    // NOP
    // 0x10aac0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10aac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10aac4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10aac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10aac8: 0x8485000e  lh          $a1, 0xE($a0)
    ctx->pc = 0x10aac8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x10aacc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10aaccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10aad0: 0x8c840054  lw          $a0, 0x54($a0)
    ctx->pc = 0x10aad0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 84)));
    // 0x10aad4: 0x8040e7c  j           func_1039F0
    ctx->pc = 0x10AAD4u;
    ctx->pc = 0x10AAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AAD4u;
            // 0x10aad8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1039F0u;
    if (runtime->hasFunction(0x1039F0u)) {
        auto targetFn = runtime->lookupFunction(0x1039F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001039F0_0x1039f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10AADCu;
    // 0x10aadc: 0x0  nop
    ctx->pc = 0x10aadcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
