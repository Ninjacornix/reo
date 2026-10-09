#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162198
// Address: 0x162198 - 0x1622f0
void sub_00162198_0x162198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162198_0x162198");
#endif

    switch (ctx->pc) {
        case 0x162250u: goto label_162250;
        case 0x162264u: goto label_162264;
        case 0x162280u: goto label_162280;
        case 0x162290u: goto label_162290;
        case 0x1622a4u: goto label_1622a4;
        case 0x1622c4u: goto label_1622c4;
        default: break;
    }

    ctx->pc = 0x162198u;

    // 0x162198: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16219c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16219cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621a0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1621a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1621a4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1621a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621a8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1621a8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621ac: 0x8c4a000c  lw          $t2, 0xC($v0)
    ctx->pc = 0x1621acu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1621b0: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x1621b0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1621b4: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x1621b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x1621b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1621b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1621bc: 0x1435021  addu        $t2, $t2, $v1
    ctx->pc = 0x1621bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x1621c0: 0xa5043  sra         $t2, $t2, 1
    ctx->pc = 0x1621c0u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 1));
    // 0x1621c4: 0x8058882  j           func_162208
    ctx->pc = 0x1621C4u;
    ctx->pc = 0x1621C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1621C4u;
            // 0x1621c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162208u;
    goto label_162208;
    ctx->pc = 0x1621CCu;
    // 0x1621cc: 0x0  nop
    ctx->pc = 0x1621ccu;
    // NOP
    // 0x1621d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1621d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1621d4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1621d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621d8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1621d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1621dc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1621dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621e0: 0x8c48000c  lw          $t0, 0xC($v0)
    ctx->pc = 0x1621e0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1621e4: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x1621e4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1621e8: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x1621e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x1621ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1621ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1621f0: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x1621f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1621f4: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x1621f4u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x1621f8: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1621f8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621fc: 0x8058882  j           func_162208
    ctx->pc = 0x1621FCu;
    ctx->pc = 0x162200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1621FCu;
            // 0x162200: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162208u;
    goto label_162208;
    ctx->pc = 0x162204u;
    // 0x162204: 0x0  nop
    ctx->pc = 0x162204u;
    // NOP
label_162208:
    // 0x162208: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x162208u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x16220c: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x16220cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x162210: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x162210u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162214: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x162214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x162218: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x162218u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16221c: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x16221cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x162220: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x162220u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162224: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x162224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x162228: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x162228u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16222c: 0xffb500b8  sd          $s5, 0xB8($sp)
    ctx->pc = 0x16222cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 21));
    // 0x162230: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x162230u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162234: 0xffb600c0  sd          $s6, 0xC0($sp)
    ctx->pc = 0x162234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 22));
    // 0x162238: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x162238u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16223c: 0xffb700c8  sd          $s7, 0xC8($sp)
    ctx->pc = 0x16223cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 200), GPR_U64(ctx, 23));
    // 0x162240: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x162240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x162244: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x162244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x162248: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162248u;
    SET_GPR_U32(ctx, 31, 0x162250u);
    ctx->pc = 0x16224Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162248u;
            // 0x16224c: 0x140b82d  daddu       $s7, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162250u; }
        if (ctx->pc != 0x162250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162250u; }
        if (ctx->pc != 0x162250u) { return; }
    }
    ctx->pc = 0x162250u;
label_162250:
    // 0x162250: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x162250u;
    {
        const bool branch_taken_0x162250 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x162250) {
            ctx->pc = 0x162254u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162250u;
            // 0x162254: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162270u;
            goto label_162270;
        }
    }
    ctx->pc = 0x162258u;
    // 0x162258: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162258u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16225c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16225Cu;
    SET_GPR_U32(ctx, 31, 0x162264u);
    ctx->pc = 0x162260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16225Cu;
            // 0x162260: 0x2484ffc8  addiu       $a0, $a0, -0x38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162264u; }
        if (ctx->pc != 0x162264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162264u; }
        if (ctx->pc != 0x162264u) { return; }
    }
    ctx->pc = 0x162264u;
label_162264:
    // 0x162264: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x162264u;
    {
        const bool branch_taken_0x162264 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162264u;
            // 0x162268: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162264) {
            ctx->pc = 0x1622C8u;
            goto label_1622c8;
        }
    }
    ctx->pc = 0x16226Cu;
    // 0x16226c: 0x0  nop
    ctx->pc = 0x16226cu;
    // NOP
label_162270:
    // 0x162270: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x162270u;
    {
        const bool branch_taken_0x162270 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162270u;
            // 0x162274: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162270) {
            ctx->pc = 0x162288u;
            goto label_162288;
        }
    }
    ctx->pc = 0x162278u;
    // 0x162278: 0xc058dd4  jal         func_163750
    ctx->pc = 0x162278u;
    SET_GPR_U32(ctx, 31, 0x162280u);
    ctx->pc = 0x16227Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162278u;
            // 0x16227c: 0x24840000  addiu       $a0, $a0, 0x0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162280u; }
        if (ctx->pc != 0x162280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162280u; }
        if (ctx->pc != 0x162280u) { return; }
    }
    ctx->pc = 0x162280u;
label_162280:
    // 0x162280: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x162280u;
    {
        const bool branch_taken_0x162280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162280u;
            // 0x162284: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162280) {
            ctx->pc = 0x1622C8u;
            goto label_1622c8;
        }
    }
    ctx->pc = 0x162288u;
label_162288:
    // 0x162288: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x162288u;
    SET_GPR_U32(ctx, 31, 0x162290u);
    ctx->pc = 0x16228Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162288u;
            // 0x16228c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162290u; }
        if (ctx->pc != 0x162290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162290u; }
        if (ctx->pc != 0x162290u) { return; }
    }
    ctx->pc = 0x162290u;
label_162290:
    // 0x162290: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x162290u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162294: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x162294u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162298: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x162298u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16229c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16229Cu;
    SET_GPR_U32(ctx, 31, 0x1622A4u);
    ctx->pc = 0x1622A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16229Cu;
            // 0x1622a0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622A4u; }
        if (ctx->pc != 0x1622A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622A4u; }
        if (ctx->pc != 0x1622A4u) { return; }
    }
    ctx->pc = 0x1622A4u;
label_1622a4:
    // 0x1622a4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1622a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1622a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622ac: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1622acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622b0: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x1622b0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622b4: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x1622b4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622b8: 0x2c0482d  daddu       $t1, $s6, $zero
    ctx->pc = 0x1622b8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622bc: 0xc05ec04  jal         func_17B010
    ctx->pc = 0x1622BCu;
    SET_GPR_U32(ctx, 31, 0x1622C4u);
    ctx->pc = 0x1622C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1622BCu;
            // 0x1622c0: 0x2e0502d  daddu       $t2, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B010u;
    if (runtime->hasFunction(0x17B010u)) {
        auto targetFn = runtime->lookupFunction(0x17B010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622C4u; }
        if (ctx->pc != 0x1622C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017B010_0x17b010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622C4u; }
        if (ctx->pc != 0x1622C4u) { return; }
    }
    ctx->pc = 0x1622C4u;
label_1622c4:
    // 0x1622c4: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x1622c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1622c8:
    // 0x1622c8: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x1622c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1622cc: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x1622ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1622d0: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x1622d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1622d4: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x1622d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1622d8: 0xdfb500b8  ld          $s5, 0xB8($sp)
    ctx->pc = 0x1622d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x1622dc: 0xdfb600c0  ld          $s6, 0xC0($sp)
    ctx->pc = 0x1622dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1622e0: 0xdfb700c8  ld          $s7, 0xC8($sp)
    ctx->pc = 0x1622e0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x1622e4: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x1622e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1622e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1622E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1622ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1622E8u;
            // 0x1622ec: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162208u: goto label_162208;
            case 0x162250u: goto label_162250;
            case 0x162264u: goto label_162264;
            case 0x162270u: goto label_162270;
            case 0x162280u: goto label_162280;
            case 0x162288u: goto label_162288;
            case 0x162290u: goto label_162290;
            case 0x1622A4u: goto label_1622a4;
            case 0x1622C4u: goto label_1622c4;
            case 0x1622C8u: goto label_1622c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1622F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
