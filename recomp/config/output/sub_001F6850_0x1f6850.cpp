#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6850
// Address: 0x1f6850 - 0x1f6b10
void sub_001F6850_0x1f6850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6850_0x1f6850");
#endif

    switch (ctx->pc) {
        case 0x1f68acu: goto label_1f68ac;
        case 0x1f68ccu: goto label_1f68cc;
        case 0x1f691cu: goto label_1f691c;
        case 0x1f69acu: goto label_1f69ac;
        case 0x1f6a30u: goto label_1f6a30;
        case 0x1f6a38u: goto label_1f6a38;
        case 0x1f6a78u: goto label_1f6a78;
        case 0x1f6a90u: goto label_1f6a90;
        case 0x1f6a98u: goto label_1f6a98;
        default: break;
    }

    ctx->pc = 0x1f6850u;

    // 0x1f6850: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f6850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f6854: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1f6854u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f6858: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f685c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f685cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6860: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f6860u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6864: 0x80840001  lb          $a0, 0x1($a0)
    ctx->pc = 0x1f6864u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1f6868: 0x10830065  beq         $a0, $v1, . + 4 + (0x65 << 2)
    ctx->pc = 0x1F6868u;
    {
        const bool branch_taken_0x1f6868 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F686Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6868u;
            // 0x1f686c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6868) {
            ctx->pc = 0x1F6A00u;
            goto label_1f6a00;
        }
    }
    ctx->pc = 0x1F6870u;
    // 0x1f6870: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1f6870u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f6874: 0x10820042  beq         $a0, $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x1F6874u;
    {
        const bool branch_taken_0x1f6874 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6874u;
            // 0x1f6878: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6874) {
            ctx->pc = 0x1F6980u;
            goto label_1f6980;
        }
    }
    ctx->pc = 0x1F687Cu;
    // 0x1f687c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f687cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6880: 0x1082001f  beq         $a0, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1F6880u;
    {
        const bool branch_taken_0x1f6880 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1f6880) {
            ctx->pc = 0x1F6900u;
            goto label_1f6900;
        }
    }
    ctx->pc = 0x1F6888u;
    // 0x1f6888: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6888u;
    {
        const bool branch_taken_0x1f6888 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6888) {
            ctx->pc = 0x1F6898u;
            goto label_1f6898;
        }
    }
    ctx->pc = 0x1F6890u;
    // 0x1f6890: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x1F6890u;
    {
        const bool branch_taken_0x1f6890 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6890u;
            // 0x1f6894: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6890) {
            ctx->pc = 0x1F6B00u;
            goto label_1f6b00;
        }
    }
    ctx->pc = 0x1F6898u;
label_1f6898:
    // 0x1f6898: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f6898u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f689c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f689cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f68a0: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1f68a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1f68a4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F68A4u;
    SET_GPR_U32(ctx, 31, 0x1F68ACu);
    ctx->pc = 0x1F68A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F68A4u;
            // 0x1f68a8: 0x24a59b40  addiu       $a1, $a1, -0x64C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68ACu; }
        if (ctx->pc != 0x1F68ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68ACu; }
        if (ctx->pc != 0x1F68ACu) { return; }
    }
    ctx->pc = 0x1F68ACu;
label_1f68ac:
    // 0x1f68ac: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f68acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f68b0: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f68b0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f68b4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1f68b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1f68b8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f68b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f68bc: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1f68bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1f68c0: 0xac22c7f8  sw          $v0, -0x3808($at)
    ctx->pc = 0x1f68c0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 2));
    // 0x1f68c4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F68C4u;
    SET_GPR_U32(ctx, 31, 0x1F68CCu);
    ctx->pc = 0x1F68C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F68C4u;
            // 0x1f68c8: 0x24a59b80  addiu       $a1, $a1, -0x6480 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68CCu; }
        if (ctx->pc != 0x1F68CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68CCu; }
        if (ctx->pc != 0x1F68CCu) { return; }
    }
    ctx->pc = 0x1F68CCu;
label_1f68cc:
    // 0x1f68cc: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x1f68ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1f68d0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f68d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f68d4: 0x24639af0  addiu       $v1, $v1, -0x6510
    ctx->pc = 0x1f68d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941424));
    // 0x1f68d8: 0x2402278f  addiu       $v0, $zero, 0x278F
    ctx->pc = 0x1f68d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10127));
    // 0x1f68dc: 0xac237420  sw          $v1, 0x7420($at)
    ctx->pc = 0x1f68dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 29728), GPR_U32(ctx, 3));
    // 0x1f68e0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f68e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f68e4: 0xa4227428  sh          $v0, 0x7428($at)
    ctx->pc = 0x1f68e4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 29736), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f68e8: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f68e8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f68ec: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f68ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f68f0: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f68f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f68f4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f68f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f68f8: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x1F68F8u;
    {
        const bool branch_taken_0x1f68f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F68FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F68F8u;
            // 0x1f68fc: 0xa6000004  sh          $zero, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f68f8) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6900u;
label_1f6900:
    // 0x1f6900: 0xae030090  sw          $v1, 0x90($s0)
    ctx->pc = 0x1f6900u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 3));
    // 0x1f6904: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f6904u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f6908: 0x8c277420  lw          $a3, 0x7420($at)
    ctx->pc = 0x1f6908u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 29728)));
    // 0x1f690c: 0x26040002  addiu       $a0, $s0, 0x2
    ctx->pc = 0x1f690cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1f6910: 0x26050004  addiu       $a1, $s0, 0x4
    ctx->pc = 0x1f6910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1f6914: 0xc0724bc  jal         func_1C92F0
    ctx->pc = 0x1F6914u;
    SET_GPR_U32(ctx, 31, 0x1F691Cu);
    ctx->pc = 0x1F6918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6914u;
            // 0x1f6918: 0x2606000c  addiu       $a2, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C92F0u;
    if (runtime->hasFunction(0x1C92F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C92F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F691Cu; }
        if (ctx->pc != 0x1F691Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C92F0_0x1c92f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F691Cu; }
        if (ctx->pc != 0x1F691Cu) { return; }
    }
    ctx->pc = 0x1F691Cu;
label_1f691c:
    // 0x1f691c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f691cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f6920: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1F6920u;
    {
        const bool branch_taken_0x1f6920 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F6924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6920u;
            // 0x1f6924: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6920) {
            ctx->pc = 0x1F6954u;
            goto label_1f6954;
        }
    }
    ctx->pc = 0x1F6928u;
    // 0x1f6928: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f6928u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f692c: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F692Cu;
    {
        const bool branch_taken_0x1f692c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f692c) {
            ctx->pc = 0x1F6944u;
            goto label_1f6944;
        }
    }
    ctx->pc = 0x1F6934u;
    // 0x1f6934: 0x10400071  beqz        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x1F6934u;
    {
        const bool branch_taken_0x1f6934 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6934) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F693Cu;
    // 0x1f693c: 0x1000006f  b           . + 4 + (0x6F << 2)
    ctx->pc = 0x1F693Cu;
    {
        const bool branch_taken_0x1f693c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f693c) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6944u;
label_1f6944:
    // 0x1f6944: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f6944u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f6948: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f6948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f694c: 0x1000006b  b           . + 4 + (0x6B << 2)
    ctx->pc = 0x1F694Cu;
    {
        const bool branch_taken_0x1f694c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F694Cu;
            // 0x1f6950: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f694c) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6954u;
label_1f6954:
    // 0x1f6954: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6954u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6958: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f695c: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f695cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6960: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6960u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6964: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6964u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6968: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6968u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f696c: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f696cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6970: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6970u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6974: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6974u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6978: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1F6978u;
    {
        const bool branch_taken_0x1f6978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F697Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6978u;
            // 0x1f697c: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6978) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6980u;
label_1f6980:
    // 0x1f6980: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f6980u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f6984: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6984u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6988: 0x94227428  lhu         $v0, 0x7428($at)
    ctx->pc = 0x1f6988u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 29736)));
    // 0x1f698c: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1f698cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1f6990: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1f6990u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1f6994: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1f6994u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1f6998: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1f6998u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1f699c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f699cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f69a0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f69a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f69a4: 0xc07d174  jal         func_1F45D0
    ctx->pc = 0x1F69A4u;
    SET_GPR_U32(ctx, 31, 0x1F69ACu);
    ctx->pc = 0x1F69A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69A4u;
            // 0x1f69a8: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45D0u;
    if (runtime->hasFunction(0x1F45D0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F69ACu; }
        if (ctx->pc != 0x1F69ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45D0_0x1f45d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F69ACu; }
        if (ctx->pc != 0x1F69ACu) { return; }
    }
    ctx->pc = 0x1F69ACu;
label_1f69ac:
    // 0x1f69ac: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F69ACu;
    {
        const bool branch_taken_0x1f69ac = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F69B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69ACu;
            // 0x1f69b0: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f69ac) {
            ctx->pc = 0x1F69E4u;
            goto label_1f69e4;
        }
    }
    ctx->pc = 0x1F69B4u;
    // 0x1f69b4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1f69b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f69b8: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f69b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f69bc: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f69bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f69c0: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f69c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f69c4: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f69c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69c8: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f69c8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69cc: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f69ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69d0: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f69d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f69d4: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f69d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f69d8: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f69d8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f69dc: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1F69DCu;
    {
        const bool branch_taken_0x1f69dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F69E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69DCu;
            // 0x1f69e0: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f69dc) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F69E4u;
label_1f69e4:
    // 0x1f69e4: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x1f69e4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f69e8: 0x24020708  addiu       $v0, $zero, 0x708
    ctx->pc = 0x1f69e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x1f69ec: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1f69ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1f69f0: 0xa2030001  sb          $v1, 0x1($s0)
    ctx->pc = 0x1f69f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f69f4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f69f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69f8: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1F69F8u;
    {
        const bool branch_taken_0x1f69f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F69FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69F8u;
            // 0x1f69fc: 0xa6020004  sh          $v0, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f69f8) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6A00u;
label_1f6a00:
    // 0x1f6a00: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6a00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6a04: 0x86020004  lh          $v0, 0x4($s0)
    ctx->pc = 0x1f6a04u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1f6a08: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f6a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f6a0c: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x1f6a0cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f6a10: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1f6a10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f6a14: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1f6a14u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1f6a18: 0x1c400013  bgtz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1F6A18u;
    {
        const bool branch_taken_0x1f6a18 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1f6a18) {
            ctx->pc = 0x1F6A68u;
            goto label_1f6a68;
        }
    }
    ctx->pc = 0x1F6A20u;
    // 0x1f6a20: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f6a20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f6a24: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6a24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6a28: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6A28u;
    SET_GPR_U32(ctx, 31, 0x1F6A30u);
    ctx->pc = 0x1F6A2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A28u;
            // 0x1f6a2c: 0x8e040010  lw          $a0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A30u; }
        if (ctx->pc != 0x1F6A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A30u; }
        if (ctx->pc != 0x1F6A30u) { return; }
    }
    ctx->pc = 0x1F6A30u;
label_1f6a30:
    // 0x1f6a30: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6A30u;
    SET_GPR_U32(ctx, 31, 0x1F6A38u);
    ctx->pc = 0x1F6A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A30u;
            // 0x1f6a34: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A38u; }
        if (ctx->pc != 0x1F6A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A38u; }
        if (ctx->pc != 0x1F6A38u) { return; }
    }
    ctx->pc = 0x1F6A38u;
label_1f6a38:
    // 0x1f6a38: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1f6a38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f6a3c: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6a40: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6a40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f6a44: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f6a44u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6a48: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6a48u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6a4c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6a4cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6a50: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6a50u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6a54: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6a54u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6a58: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6a58u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6a5c: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6a5cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6a60: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1F6A60u;
    {
        const bool branch_taken_0x1f6a60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A60u;
            // 0x1f6a64: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6a60) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6A68u;
label_1f6a68:
    // 0x1f6a68: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f6a68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f6a6c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1f6a6cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1f6a70: 0xc075a4c  jal         func_1D6930
    ctx->pc = 0x1F6A70u;
    SET_GPR_U32(ctx, 31, 0x1F6A78u);
    ctx->pc = 0x1F6A74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A70u;
            // 0x1f6a74: 0x24a5b6b4  addiu       $a1, $a1, -0x494C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948532));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6930u;
    if (runtime->hasFunction(0x1D6930u)) {
        auto targetFn = runtime->lookupFunction(0x1D6930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A78u; }
        if (ctx->pc != 0x1F6A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6930_0x1d6930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A78u; }
        if (ctx->pc != 0x1F6A78u) { return; }
    }
    ctx->pc = 0x1F6A78u;
label_1f6a78:
    // 0x1f6a78: 0x4410013  bgez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1F6A78u;
    {
        const bool branch_taken_0x1f6a78 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A78u;
            // 0x1f6a7c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6a78) {
            ctx->pc = 0x1F6AC8u;
            goto label_1f6ac8;
        }
    }
    ctx->pc = 0x1F6A80u;
    // 0x1f6a80: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6a84: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6a84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6a88: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6A88u;
    SET_GPR_U32(ctx, 31, 0x1F6A90u);
    ctx->pc = 0x1F6A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A88u;
            // 0x1f6a8c: 0x8e040010  lw          $a0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A90u; }
        if (ctx->pc != 0x1F6A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A90u; }
        if (ctx->pc != 0x1F6A90u) { return; }
    }
    ctx->pc = 0x1F6A90u;
label_1f6a90:
    // 0x1f6a90: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6A90u;
    SET_GPR_U32(ctx, 31, 0x1F6A98u);
    ctx->pc = 0x1F6A94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A90u;
            // 0x1f6a94: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A98u; }
        if (ctx->pc != 0x1F6A98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A98u; }
        if (ctx->pc != 0x1F6A98u) { return; }
    }
    ctx->pc = 0x1F6A98u;
label_1f6a98:
    // 0x1f6a98: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1f6a98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f6a9c: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6aa0: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f6aa4: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f6aa4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6aa8: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6aa8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6aac: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6aacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6ab0: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6ab0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6ab4: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6ab4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ab8: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6ab8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6abc: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6abcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ac0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1F6AC0u;
    {
        const bool branch_taken_0x1f6ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6AC0u;
            // 0x1f6ac4: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ac0) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6AC8u;
label_1f6ac8:
    // 0x1f6ac8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f6ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f6acc: 0x8423b6b4  lh          $v1, -0x494C($at)
    ctx->pc = 0x1f6accu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948532)));
    // 0x1f6ad0: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1F6AD0u;
    {
        const bool branch_taken_0x1f6ad0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F6AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6AD0u;
            // 0x1f6ad4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ad0) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6AD8u;
    // 0x1f6ad8: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6adc: 0xae030088  sw          $v1, 0x88($s0)
    ctx->pc = 0x1f6adcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 3));
    // 0x1f6ae0: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1f6ae0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1f6ae4: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F6AE4u;
    {
        const bool branch_taken_0x1f6ae4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6AE4u;
            // 0x1f6ae8: 0x24620001  addiu       $v0, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ae4) {
            ctx->pc = 0x1F6AF0u;
            goto label_1f6af0;
        }
    }
    ctx->pc = 0x1F6AECu;
    // 0x1f6aec: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f6aecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1f6af0:
    // 0x1f6af0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6af0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6af4: 0x24020708  addiu       $v0, $zero, 0x708
    ctx->pc = 0x1f6af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x1f6af8: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x1f6af8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
label_1f6afc:
    // 0x1f6afc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6afcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f6b00:
    // 0x1f6b00: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6b00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6b04: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6b04u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6b08: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6B08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B08u;
            // 0x1f6b0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6B10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
