#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001622F0
// Address: 0x1622f0 - 0x162448
void sub_001622F0_0x1622f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001622F0_0x1622f0");
#endif

    switch (ctx->pc) {
        case 0x1623a8u: goto label_1623a8;
        case 0x1623bcu: goto label_1623bc;
        case 0x1623d8u: goto label_1623d8;
        case 0x1623e8u: goto label_1623e8;
        case 0x1623fcu: goto label_1623fc;
        case 0x16241cu: goto label_16241c;
        default: break;
    }

    ctx->pc = 0x1622f0u;

    // 0x1622f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1622f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1622f4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1622f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1622f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1622fc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1622fcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162300: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x162300u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162304: 0x8c4a000c  lw          $t2, 0xC($v0)
    ctx->pc = 0x162304u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x162308: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x162308u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x16230c: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x16230cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x162310: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162314: 0x1435021  addu        $t2, $t2, $v1
    ctx->pc = 0x162314u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x162318: 0xa5043  sra         $t2, $t2, 1
    ctx->pc = 0x162318u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 1));
    // 0x16231c: 0x80588d8  j           func_162360
    ctx->pc = 0x16231Cu;
    ctx->pc = 0x162320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16231Cu;
            // 0x162320: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162360u;
    goto label_162360;
    ctx->pc = 0x162324u;
    // 0x162324: 0x0  nop
    ctx->pc = 0x162324u;
    // NOP
    // 0x162328: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16232c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16232cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162330: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162334: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x162334u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162338: 0x8c48000c  lw          $t0, 0xC($v0)
    ctx->pc = 0x162338u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x16233c: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x16233cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x162340: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x162340u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x162344: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162344u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162348: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x162348u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x16234c: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x16234cu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x162350: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x162350u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162354: 0x80588d8  j           func_162360
    ctx->pc = 0x162354u;
    ctx->pc = 0x162358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162354u;
            // 0x162358: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162360u;
    goto label_162360;
    ctx->pc = 0x16235Cu;
    // 0x16235c: 0x0  nop
    ctx->pc = 0x16235cu;
    // NOP
label_162360:
    // 0x162360: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x162360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x162364: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x162364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x162368: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x162368u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16236c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16236cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x162370: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x162370u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162374: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x162374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x162378: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x162378u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16237c: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x16237cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x162380: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x162380u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162384: 0xffb500b8  sd          $s5, 0xB8($sp)
    ctx->pc = 0x162384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 21));
    // 0x162388: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x162388u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16238c: 0xffb600c0  sd          $s6, 0xC0($sp)
    ctx->pc = 0x16238cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 22));
    // 0x162390: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x162390u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162394: 0xffb700c8  sd          $s7, 0xC8($sp)
    ctx->pc = 0x162394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 200), GPR_U64(ctx, 23));
    // 0x162398: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x162398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x16239c: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x16239cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x1623a0: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1623A0u;
    SET_GPR_U32(ctx, 31, 0x1623A8u);
    ctx->pc = 0x1623A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623A0u;
            // 0x1623a4: 0x140b82d  daddu       $s7, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623A8u; }
        if (ctx->pc != 0x1623A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623A8u; }
        if (ctx->pc != 0x1623A8u) { return; }
    }
    ctx->pc = 0x1623A8u;
label_1623a8:
    // 0x1623a8: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1623A8u;
    {
        const bool branch_taken_0x1623a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1623a8) {
            ctx->pc = 0x1623ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1623A8u;
            // 0x1623ac: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1623C8u;
            goto label_1623c8;
        }
    }
    ctx->pc = 0x1623B0u;
    // 0x1623b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1623b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1623b4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1623B4u;
    SET_GPR_U32(ctx, 31, 0x1623BCu);
    ctx->pc = 0x1623B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623B4u;
            // 0x1623b8: 0x24840038  addiu       $a0, $a0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623BCu; }
        if (ctx->pc != 0x1623BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623BCu; }
        if (ctx->pc != 0x1623BCu) { return; }
    }
    ctx->pc = 0x1623BCu;
label_1623bc:
    // 0x1623bc: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1623BCu;
    {
        const bool branch_taken_0x1623bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1623C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1623BCu;
            // 0x1623c0: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1623bc) {
            ctx->pc = 0x162420u;
            goto label_162420;
        }
    }
    ctx->pc = 0x1623C4u;
    // 0x1623c4: 0x0  nop
    ctx->pc = 0x1623c4u;
    // NOP
label_1623c8:
    // 0x1623c8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1623C8u;
    {
        const bool branch_taken_0x1623c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1623CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1623C8u;
            // 0x1623cc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1623c8) {
            ctx->pc = 0x1623E0u;
            goto label_1623e0;
        }
    }
    ctx->pc = 0x1623D0u;
    // 0x1623d0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1623D0u;
    SET_GPR_U32(ctx, 31, 0x1623D8u);
    ctx->pc = 0x1623D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623D0u;
            // 0x1623d4: 0x24840070  addiu       $a0, $a0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623D8u; }
        if (ctx->pc != 0x1623D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623D8u; }
        if (ctx->pc != 0x1623D8u) { return; }
    }
    ctx->pc = 0x1623D8u;
label_1623d8:
    // 0x1623d8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1623D8u;
    {
        const bool branch_taken_0x1623d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1623DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1623D8u;
            // 0x1623dc: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1623d8) {
            ctx->pc = 0x162420u;
            goto label_162420;
        }
    }
    ctx->pc = 0x1623E0u;
label_1623e0:
    // 0x1623e0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1623E0u;
    SET_GPR_U32(ctx, 31, 0x1623E8u);
    ctx->pc = 0x1623E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623E0u;
            // 0x1623e4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623E8u; }
        if (ctx->pc != 0x1623E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623E8u; }
        if (ctx->pc != 0x1623E8u) { return; }
    }
    ctx->pc = 0x1623E8u;
label_1623e8:
    // 0x1623e8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1623e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1623ec: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1623ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1623f0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1623f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1623f4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x1623F4u;
    SET_GPR_U32(ctx, 31, 0x1623FCu);
    ctx->pc = 0x1623F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623F4u;
            // 0x1623f8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623FCu; }
        if (ctx->pc != 0x1623FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623FCu; }
        if (ctx->pc != 0x1623FCu) { return; }
    }
    ctx->pc = 0x1623FCu;
label_1623fc:
    // 0x1623fc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1623fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162400: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162400u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162404: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x162404u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162408: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x162408u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16240c: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x16240cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162410: 0x2c0482d  daddu       $t1, $s6, $zero
    ctx->pc = 0x162410u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162414: 0xc05eeba  jal         func_17BAE8
    ctx->pc = 0x162414u;
    SET_GPR_U32(ctx, 31, 0x16241Cu);
    ctx->pc = 0x162418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162414u;
            // 0x162418: 0x2e0502d  daddu       $t2, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BAE8u;
    if (runtime->hasFunction(0x17BAE8u)) {
        auto targetFn = runtime->lookupFunction(0x17BAE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16241Cu; }
        if (ctx->pc != 0x16241Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BAE8_0x17bae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16241Cu; }
        if (ctx->pc != 0x16241Cu) { return; }
    }
    ctx->pc = 0x16241Cu;
label_16241c:
    // 0x16241c: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x16241cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_162420:
    // 0x162420: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x162420u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x162424: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x162424u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x162428: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x162428u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x16242c: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x16242cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x162430: 0xdfb500b8  ld          $s5, 0xB8($sp)
    ctx->pc = 0x162430u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x162434: 0xdfb600c0  ld          $s6, 0xC0($sp)
    ctx->pc = 0x162434u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x162438: 0xdfb700c8  ld          $s7, 0xC8($sp)
    ctx->pc = 0x162438u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x16243c: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x16243cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x162440: 0x3e00008  jr          $ra
    ctx->pc = 0x162440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162440u;
            // 0x162444: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162360u: goto label_162360;
            case 0x1623A8u: goto label_1623a8;
            case 0x1623BCu: goto label_1623bc;
            case 0x1623C8u: goto label_1623c8;
            case 0x1623D8u: goto label_1623d8;
            case 0x1623E0u: goto label_1623e0;
            case 0x1623E8u: goto label_1623e8;
            case 0x1623FCu: goto label_1623fc;
            case 0x16241Cu: goto label_16241c;
            case 0x162420u: goto label_162420;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
