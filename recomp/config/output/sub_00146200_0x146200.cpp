#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146200
// Address: 0x146200 - 0x1464f0
void sub_00146200_0x146200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146200_0x146200");
#endif

    switch (ctx->pc) {
        case 0x146230u: goto label_146230;
        case 0x14623cu: goto label_14623c;
        case 0x146248u: goto label_146248;
        case 0x146254u: goto label_146254;
        case 0x146260u: goto label_146260;
        case 0x14626cu: goto label_14626c;
        case 0x146278u: goto label_146278;
        case 0x146288u: goto label_146288;
        case 0x1462b8u: goto label_1462b8;
        case 0x1462c8u: goto label_1462c8;
        case 0x1462d4u: goto label_1462d4;
        case 0x1462dcu: goto label_1462dc;
        case 0x1462e8u: goto label_1462e8;
        case 0x1462f8u: goto label_1462f8;
        case 0x146304u: goto label_146304;
        case 0x14630cu: goto label_14630c;
        case 0x146318u: goto label_146318;
        case 0x14632cu: goto label_14632c;
        case 0x146338u: goto label_146338;
        case 0x1463e8u: goto label_1463e8;
        case 0x1463f0u: goto label_1463f0;
        case 0x146408u: goto label_146408;
        case 0x146418u: goto label_146418;
        case 0x14642cu: goto label_14642c;
        case 0x146478u: goto label_146478;
        case 0x146484u: goto label_146484;
        case 0x146490u: goto label_146490;
        case 0x14649cu: goto label_14649c;
        case 0x1464a8u: goto label_1464a8;
        case 0x1464b4u: goto label_1464b4;
        case 0x1464c0u: goto label_1464c0;
        case 0x1464ccu: goto label_1464cc;
        case 0x1464d8u: goto label_1464d8;
        default: break;
    }

    ctx->pc = 0x146200u;

    // 0x146200: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x146200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x146204: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x146204u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146208: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14620c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x14620cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146210: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x146210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x146214: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x146214u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146218: 0xae000100  sw          $zero, 0x100($s0)
    ctx->pc = 0x146218u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 256), GPR_U32(ctx, 0));
    // 0x14621c: 0x8e020868  lw          $v0, 0x868($s0)
    ctx->pc = 0x14621cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2152)));
    // 0x146220: 0xae03086c  sw          $v1, 0x86C($s0)
    ctx->pc = 0x146220u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2156), GPR_U32(ctx, 3));
    // 0x146224: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x146224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x146228: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146228u;
    SET_GPR_U32(ctx, 31, 0x146230u);
    ctx->pc = 0x14622Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146228u;
            // 0x14622c: 0xae020864  sw          $v0, 0x864($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2148), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146230u; }
        if (ctx->pc != 0x146230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146230u; }
        if (ctx->pc != 0x146230u) { return; }
    }
    ctx->pc = 0x146230u;
label_146230:
    // 0x146230: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146230u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146234: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146234u;
    SET_GPR_U32(ctx, 31, 0x14623Cu);
    ctx->pc = 0x146238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146234u;
            // 0x146238: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14623Cu; }
        if (ctx->pc != 0x14623Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14623Cu; }
        if (ctx->pc != 0x14623Cu) { return; }
    }
    ctx->pc = 0x14623Cu;
label_14623c:
    // 0x14623c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14623cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146240: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146240u;
    SET_GPR_U32(ctx, 31, 0x146248u);
    ctx->pc = 0x146244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146240u;
            // 0x146244: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146248u; }
        if (ctx->pc != 0x146248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146248u; }
        if (ctx->pc != 0x146248u) { return; }
    }
    ctx->pc = 0x146248u;
label_146248:
    // 0x146248: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146248u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14624c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x14624Cu;
    SET_GPR_U32(ctx, 31, 0x146254u);
    ctx->pc = 0x146250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14624Cu;
            // 0x146250: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146254u; }
        if (ctx->pc != 0x146254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146254u; }
        if (ctx->pc != 0x146254u) { return; }
    }
    ctx->pc = 0x146254u;
label_146254:
    // 0x146254: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146254u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146258: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146258u;
    SET_GPR_U32(ctx, 31, 0x146260u);
    ctx->pc = 0x14625Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146258u;
            // 0x14625c: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146260u; }
        if (ctx->pc != 0x146260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146260u; }
        if (ctx->pc != 0x146260u) { return; }
    }
    ctx->pc = 0x146260u;
label_146260:
    // 0x146260: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146264: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146264u;
    SET_GPR_U32(ctx, 31, 0x14626Cu);
    ctx->pc = 0x146268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146264u;
            // 0x146268: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14626Cu; }
        if (ctx->pc != 0x14626Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14626Cu; }
        if (ctx->pc != 0x14626Cu) { return; }
    }
    ctx->pc = 0x14626Cu;
label_14626c:
    // 0x14626c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14626cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146270: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146270u;
    SET_GPR_U32(ctx, 31, 0x146278u);
    ctx->pc = 0x146274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146270u;
            // 0x146274: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146278u; }
        if (ctx->pc != 0x146278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146278u; }
        if (ctx->pc != 0x146278u) { return; }
    }
    ctx->pc = 0x146278u;
label_146278:
    // 0x146278: 0xae0201bc  sw          $v0, 0x1BC($s0)
    ctx->pc = 0x146278u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 444), GPR_U32(ctx, 2));
    // 0x14627c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14627cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146280: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146280u;
    SET_GPR_U32(ctx, 31, 0x146288u);
    ctx->pc = 0x146284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146280u;
            // 0x146284: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146288u; }
        if (ctx->pc != 0x146288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146288u; }
        if (ctx->pc != 0x146288u) { return; }
    }
    ctx->pc = 0x146288u;
label_146288:
    // 0x146288: 0xae0201c0  sw          $v0, 0x1C0($s0)
    ctx->pc = 0x146288u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 448), GPR_U32(ctx, 2));
    // 0x14628c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14628cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146290: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x146290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146294: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146294u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146298: 0x805178a  j           func_145E28
    ctx->pc = 0x146298u;
    ctx->pc = 0x14629Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146298u;
            // 0x14629c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145E28u;
    if (runtime->hasFunction(0x145E28u)) {
        auto targetFn = runtime->lookupFunction(0x145E28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00145E28_0x145e28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1462A0u;
    // 0x1462a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1462a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1462a4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1462a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1462a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1462a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1462ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1462acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1462b0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1462B0u;
    SET_GPR_U32(ctx, 31, 0x1462B8u);
    ctx->pc = 0x1462B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462B0u;
            // 0x1462b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462B8u; }
        if (ctx->pc != 0x1462B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462B8u; }
        if (ctx->pc != 0x1462B8u) { return; }
    }
    ctx->pc = 0x1462B8u;
label_1462b8:
    // 0x1462b8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1462B8u;
    {
        const bool branch_taken_0x1462b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1462BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1462B8u;
            // 0x1462bc: 0xae020858  sw          $v0, 0x858($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2136), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1462b8) {
            ctx->pc = 0x1462DCu;
            goto label_1462dc;
        }
    }
    ctx->pc = 0x1462C0u;
    // 0x1462c0: 0xc051496  jal         func_145258
    ctx->pc = 0x1462C0u;
    SET_GPR_U32(ctx, 31, 0x1462C8u);
    ctx->pc = 0x1462C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462C0u;
            // 0x1462c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462C8u; }
        if (ctx->pc != 0x1462C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462C8u; }
        if (ctx->pc != 0x1462C8u) { return; }
    }
    ctx->pc = 0x1462C8u;
label_1462c8:
    // 0x1462c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1462c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1462cc: 0xc05148a  jal         func_145228
    ctx->pc = 0x1462CCu;
    SET_GPR_U32(ctx, 31, 0x1462D4u);
    ctx->pc = 0x1462D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462CCu;
            // 0x1462d0: 0x3c055000  lui         $a1, 0x5000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20480 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462D4u; }
        if (ctx->pc != 0x1462D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462D4u; }
        if (ctx->pc != 0x1462D4u) { return; }
    }
    ctx->pc = 0x1462D4u;
label_1462d4:
    // 0x1462d4: 0xc051496  jal         func_145258
    ctx->pc = 0x1462D4u;
    SET_GPR_U32(ctx, 31, 0x1462DCu);
    ctx->pc = 0x1462D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462D4u;
            // 0x1462d8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462DCu; }
        if (ctx->pc != 0x1462DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462DCu; }
        if (ctx->pc != 0x1462DCu) { return; }
    }
    ctx->pc = 0x1462DCu;
label_1462dc:
    // 0x1462dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1462dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1462e0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1462E0u;
    SET_GPR_U32(ctx, 31, 0x1462E8u);
    ctx->pc = 0x1462E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462E0u;
            // 0x1462e4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462E8u; }
        if (ctx->pc != 0x1462E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462E8u; }
        if (ctx->pc != 0x1462E8u) { return; }
    }
    ctx->pc = 0x1462E8u;
label_1462e8:
    // 0x1462e8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1462E8u;
    {
        const bool branch_taken_0x1462e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1462ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1462E8u;
            // 0x1462ec: 0xae02085c  sw          $v0, 0x85C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2140), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1462e8) {
            ctx->pc = 0x14630Cu;
            goto label_14630c;
        }
    }
    ctx->pc = 0x1462F0u;
    // 0x1462f0: 0xc051496  jal         func_145258
    ctx->pc = 0x1462F0u;
    SET_GPR_U32(ctx, 31, 0x1462F8u);
    ctx->pc = 0x1462F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462F0u;
            // 0x1462f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462F8u; }
        if (ctx->pc != 0x1462F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1462F8u; }
        if (ctx->pc != 0x1462F8u) { return; }
    }
    ctx->pc = 0x1462F8u;
label_1462f8:
    // 0x1462f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1462f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1462fc: 0xc05148a  jal         func_145228
    ctx->pc = 0x1462FCu;
    SET_GPR_U32(ctx, 31, 0x146304u);
    ctx->pc = 0x146300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1462FCu;
            // 0x146300: 0x3c055800  lui         $a1, 0x5800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22528 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146304u; }
        if (ctx->pc != 0x146304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146304u; }
        if (ctx->pc != 0x146304u) { return; }
    }
    ctx->pc = 0x146304u;
label_146304:
    // 0x146304: 0xc051496  jal         func_145258
    ctx->pc = 0x146304u;
    SET_GPR_U32(ctx, 31, 0x14630Cu);
    ctx->pc = 0x146308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146304u;
            // 0x146308: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14630Cu; }
        if (ctx->pc != 0x14630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14630Cu; }
        if (ctx->pc != 0x14630Cu) { return; }
    }
    ctx->pc = 0x14630Cu;
label_14630c:
    // 0x14630c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14630cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146310: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146310u;
    SET_GPR_U32(ctx, 31, 0x146318u);
    ctx->pc = 0x146314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146310u;
            // 0x146314: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146318u; }
        if (ctx->pc != 0x146318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146318u; }
        if (ctx->pc != 0x146318u) { return; }
    }
    ctx->pc = 0x146318u;
label_146318:
    // 0x146318: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x146318u;
    {
        const bool branch_taken_0x146318 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14631Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146318u;
            // 0x14631c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146318) {
            ctx->pc = 0x14632Cu;
            goto label_14632c;
        }
    }
    ctx->pc = 0x146320u;
    // 0x146320: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146320u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146324: 0xc05221c  jal         func_148870
    ctx->pc = 0x146324u;
    SET_GPR_U32(ctx, 31, 0x14632Cu);
    ctx->pc = 0x146328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146324u;
            // 0x146328: 0x24a5df28  addiu       $a1, $a1, -0x20D8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958888));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14632Cu; }
        if (ctx->pc != 0x14632Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14632Cu; }
        if (ctx->pc != 0x14632Cu) { return; }
    }
    ctx->pc = 0x14632Cu;
label_14632c:
    // 0x14632c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14632cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146330: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146330u;
    SET_GPR_U32(ctx, 31, 0x146338u);
    ctx->pc = 0x146334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146330u;
            // 0x146334: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146338u; }
        if (ctx->pc != 0x146338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146338u; }
        if (ctx->pc != 0x146338u) { return; }
    }
    ctx->pc = 0x146338u;
label_146338:
    // 0x146338: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x146338u;
    {
        const bool branch_taken_0x146338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14633Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146338u;
            // 0x14633c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146338) {
            ctx->pc = 0x146358u;
            goto label_146358;
        }
    }
    ctx->pc = 0x146340u;
    // 0x146340: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146340u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146344: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x146344u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x146348: 0x24a5df50  addiu       $a1, $a1, -0x20B0
    ctx->pc = 0x146348u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958928));
    // 0x14634c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14634cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146350: 0x805221c  j           func_148870
    ctx->pc = 0x146350u;
    ctx->pc = 0x146354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146350u;
            // 0x146354: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00148870_0x148870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x146358u;
label_146358:
    // 0x146358: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146358u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14635c: 0x3e00008  jr          $ra
    ctx->pc = 0x14635Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14635Cu;
            // 0x146360: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146230u: goto label_146230;
            case 0x14623Cu: goto label_14623c;
            case 0x146248u: goto label_146248;
            case 0x146254u: goto label_146254;
            case 0x146260u: goto label_146260;
            case 0x14626Cu: goto label_14626c;
            case 0x146278u: goto label_146278;
            case 0x146288u: goto label_146288;
            case 0x1462B8u: goto label_1462b8;
            case 0x1462C8u: goto label_1462c8;
            case 0x1462D4u: goto label_1462d4;
            case 0x1462DCu: goto label_1462dc;
            case 0x1462E8u: goto label_1462e8;
            case 0x1462F8u: goto label_1462f8;
            case 0x146304u: goto label_146304;
            case 0x14630Cu: goto label_14630c;
            case 0x146318u: goto label_146318;
            case 0x14632Cu: goto label_14632c;
            case 0x146338u: goto label_146338;
            case 0x146358u: goto label_146358;
            case 0x1463B4u: goto label_1463b4;
            case 0x1463C0u: goto label_1463c0;
            case 0x1463C8u: goto label_1463c8;
            case 0x1463D0u: goto label_1463d0;
            case 0x1463E8u: goto label_1463e8;
            case 0x1463F0u: goto label_1463f0;
            case 0x146408u: goto label_146408;
            case 0x146418u: goto label_146418;
            case 0x14642Cu: goto label_14642c;
            case 0x146438u: goto label_146438;
            case 0x146478u: goto label_146478;
            case 0x146484u: goto label_146484;
            case 0x146490u: goto label_146490;
            case 0x14649Cu: goto label_14649c;
            case 0x1464A8u: goto label_1464a8;
            case 0x1464B4u: goto label_1464b4;
            case 0x1464C0u: goto label_1464c0;
            case 0x1464CCu: goto label_1464cc;
            case 0x1464D8u: goto label_1464d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146364u;
    // 0x146364: 0x0  nop
    ctx->pc = 0x146364u;
    // NOP
    // 0x146368: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x146368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x14636c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x14636cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x146370: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x146370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x146374: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x146374u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146378: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x146378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x14637c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x14637cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x146380: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x146380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x146384: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x146384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x146388: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14638c: 0x8e220154  lw          $v0, 0x154($s1)
    ctx->pc = 0x14638cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 340)));
    // 0x146390: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x146390u;
    {
        const bool branch_taken_0x146390 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x146390) {
            ctx->pc = 0x146394u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146390u;
            // 0x146394: 0x8e23018c  lw          $v1, 0x18C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 396)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1463B4u;
            goto label_1463b4;
        }
    }
    ctx->pc = 0x146398u;
    // 0x146398: 0x8e22019c  lw          $v0, 0x19C($s1)
    ctx->pc = 0x146398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 412)));
    // 0x14639c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x14639Cu;
    {
        const bool branch_taken_0x14639c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1463A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14639Cu;
            // 0x1463a0: 0x24130002  addiu       $s3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14639c) {
            ctx->pc = 0x1463C0u;
            goto label_1463c0;
        }
    }
    ctx->pc = 0x1463A4u;
    // 0x1463a4: 0x8e230190  lw          $v1, 0x190($s1)
    ctx->pc = 0x1463a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 400)));
    // 0x1463a8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1463a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1463ac: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1463ACu;
    {
        const bool branch_taken_0x1463ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1463B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1463ACu;
            // 0x1463b0: 0x43980b  movn        $s3, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1463ac) {
            ctx->pc = 0x1463D0u;
            goto label_1463d0;
        }
    }
    ctx->pc = 0x1463B4u;
label_1463b4:
    // 0x1463b4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1463b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1463b8: 0x50620003  beql        $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1463B8u;
    {
        const bool branch_taken_0x1463b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1463b8) {
            ctx->pc = 0x1463BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1463B8u;
            // 0x1463bc: 0x8e22019c  lw          $v0, 0x19C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 412)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1463C8u;
            goto label_1463c8;
        }
    }
    ctx->pc = 0x1463C0u;
label_1463c0:
    // 0x1463c0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1463C0u;
    {
        const bool branch_taken_0x1463c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1463C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1463C0u;
            // 0x1463c4: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1463c0) {
            ctx->pc = 0x1463D0u;
            goto label_1463d0;
        }
    }
    ctx->pc = 0x1463C8u;
label_1463c8:
    // 0x1463c8: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x1463c8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1463cc: 0x62980b  movn        $s3, $v1, $v0
    ctx->pc = 0x1463ccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
label_1463d0:
    // 0x1463d0: 0x1a600019  blez        $s3, . + 4 + (0x19 << 2)
    ctx->pc = 0x1463D0u;
    {
        const bool branch_taken_0x1463d0 = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x1463D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1463D0u;
            // 0x1463d4: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1463d0) {
            ctx->pc = 0x146438u;
            goto label_146438;
        }
    }
    ctx->pc = 0x1463D8u;
    // 0x1463d8: 0x263501a4  addiu       $s5, $s1, 0x1A4
    ctx->pc = 0x1463d8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), 420));
    // 0x1463dc: 0x263401b0  addiu       $s4, $s1, 0x1B0
    ctx->pc = 0x1463dcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 432));
    // 0x1463e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1463e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1463e4: 0x0  nop
    ctx->pc = 0x1463e4u;
    // NOP
label_1463e8:
    // 0x1463e8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1463E8u;
    SET_GPR_U32(ctx, 31, 0x1463F0u);
    ctx->pc = 0x1463ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1463E8u;
            // 0x1463ec: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1463F0u; }
        if (ctx->pc != 0x1463F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1463F0u; }
        if (ctx->pc != 0x1463F0u) { return; }
    }
    ctx->pc = 0x1463F0u;
label_1463f0:
    // 0x1463f0: 0x128080  sll         $s0, $s2, 2
    ctx->pc = 0x1463f0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1463f4: 0x2b01821  addu        $v1, $s5, $s0
    ctx->pc = 0x1463f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
    // 0x1463f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1463f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1463fc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1463fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x146400: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146400u;
    SET_GPR_U32(ctx, 31, 0x146408u);
    ctx->pc = 0x146404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146400u;
            // 0x146404: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146408u; }
        if (ctx->pc != 0x146408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146408u; }
        if (ctx->pc != 0x146408u) { return; }
    }
    ctx->pc = 0x146408u;
label_146408:
    // 0x146408: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x146408u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x14640c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14640cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146410: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146410u;
    SET_GPR_U32(ctx, 31, 0x146418u);
    ctx->pc = 0x146414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146410u;
            // 0x146414: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146418u; }
        if (ctx->pc != 0x146418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146418u; }
        if (ctx->pc != 0x146418u) { return; }
    }
    ctx->pc = 0x146418u;
label_146418:
    // 0x146418: 0x2908021  addu        $s0, $s4, $s0
    ctx->pc = 0x146418u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x14641c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14641cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146420: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x146420u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x146424: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146424u;
    SET_GPR_U32(ctx, 31, 0x14642Cu);
    ctx->pc = 0x146428u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146424u;
            // 0x146428: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14642Cu; }
        if (ctx->pc != 0x14642Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14642Cu; }
        if (ctx->pc != 0x14642Cu) { return; }
    }
    ctx->pc = 0x14642Cu;
label_14642c:
    // 0x14642c: 0x253182a  slt         $v1, $s2, $s3
    ctx->pc = 0x14642cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x146430: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x146430u;
    {
        const bool branch_taken_0x146430 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x146434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146430u;
            // 0x146434: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146430) {
            ctx->pc = 0x1463E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1463e8;
        }
    }
    ctx->pc = 0x146438u;
label_146438:
    // 0x146438: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x146438u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x14643c: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x14643cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x146440: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x146440u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x146444: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x146444u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x146448: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x146448u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14644c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x14644cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146450: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146450u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146454: 0x3e00008  jr          $ra
    ctx->pc = 0x146454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146454u;
            // 0x146458: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146230u: goto label_146230;
            case 0x14623Cu: goto label_14623c;
            case 0x146248u: goto label_146248;
            case 0x146254u: goto label_146254;
            case 0x146260u: goto label_146260;
            case 0x14626Cu: goto label_14626c;
            case 0x146278u: goto label_146278;
            case 0x146288u: goto label_146288;
            case 0x1462B8u: goto label_1462b8;
            case 0x1462C8u: goto label_1462c8;
            case 0x1462D4u: goto label_1462d4;
            case 0x1462DCu: goto label_1462dc;
            case 0x1462E8u: goto label_1462e8;
            case 0x1462F8u: goto label_1462f8;
            case 0x146304u: goto label_146304;
            case 0x14630Cu: goto label_14630c;
            case 0x146318u: goto label_146318;
            case 0x14632Cu: goto label_14632c;
            case 0x146338u: goto label_146338;
            case 0x146358u: goto label_146358;
            case 0x1463B4u: goto label_1463b4;
            case 0x1463C0u: goto label_1463c0;
            case 0x1463C8u: goto label_1463c8;
            case 0x1463D0u: goto label_1463d0;
            case 0x1463E8u: goto label_1463e8;
            case 0x1463F0u: goto label_1463f0;
            case 0x146408u: goto label_146408;
            case 0x146418u: goto label_146418;
            case 0x14642Cu: goto label_14642c;
            case 0x146438u: goto label_146438;
            case 0x146478u: goto label_146478;
            case 0x146484u: goto label_146484;
            case 0x146490u: goto label_146490;
            case 0x14649Cu: goto label_14649c;
            case 0x1464A8u: goto label_1464a8;
            case 0x1464B4u: goto label_1464b4;
            case 0x1464C0u: goto label_1464c0;
            case 0x1464CCu: goto label_1464cc;
            case 0x1464D8u: goto label_1464d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14645Cu;
    // 0x14645c: 0x0  nop
    ctx->pc = 0x14645cu;
    // NOP
    // 0x146460: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x146460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x146464: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x146464u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146468: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14646c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x14646cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x146470: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146470u;
    SET_GPR_U32(ctx, 31, 0x146478u);
    ctx->pc = 0x146474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146470u;
            // 0x146474: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146478u; }
        if (ctx->pc != 0x146478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146478u; }
        if (ctx->pc != 0x146478u) { return; }
    }
    ctx->pc = 0x146478u;
label_146478:
    // 0x146478: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146478u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14647c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x14647Cu;
    SET_GPR_U32(ctx, 31, 0x146484u);
    ctx->pc = 0x146480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14647Cu;
            // 0x146480: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146484u; }
        if (ctx->pc != 0x146484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146484u; }
        if (ctx->pc != 0x146484u) { return; }
    }
    ctx->pc = 0x146484u;
label_146484:
    // 0x146484: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146484u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146488: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146488u;
    SET_GPR_U32(ctx, 31, 0x146490u);
    ctx->pc = 0x14648Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146488u;
            // 0x14648c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146490u; }
        if (ctx->pc != 0x146490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146490u; }
        if (ctx->pc != 0x146490u) { return; }
    }
    ctx->pc = 0x146490u;
label_146490:
    // 0x146490: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146490u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146494: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146494u;
    SET_GPR_U32(ctx, 31, 0x14649Cu);
    ctx->pc = 0x146498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146494u;
            // 0x146498: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14649Cu; }
        if (ctx->pc != 0x14649Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14649Cu; }
        if (ctx->pc != 0x14649Cu) { return; }
    }
    ctx->pc = 0x14649Cu;
label_14649c:
    // 0x14649c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14649cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464a0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464A0u;
    SET_GPR_U32(ctx, 31, 0x1464A8u);
    ctx->pc = 0x1464A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464A0u;
            // 0x1464a4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464A8u; }
        if (ctx->pc != 0x1464A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464A8u; }
        if (ctx->pc != 0x1464A8u) { return; }
    }
    ctx->pc = 0x1464A8u;
label_1464a8:
    // 0x1464a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464ac: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464ACu;
    SET_GPR_U32(ctx, 31, 0x1464B4u);
    ctx->pc = 0x1464B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464ACu;
            // 0x1464b0: 0x24050014  addiu       $a1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464B4u; }
        if (ctx->pc != 0x1464B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464B4u; }
        if (ctx->pc != 0x1464B4u) { return; }
    }
    ctx->pc = 0x1464B4u;
label_1464b4:
    // 0x1464b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464b8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464B8u;
    SET_GPR_U32(ctx, 31, 0x1464C0u);
    ctx->pc = 0x1464BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464B8u;
            // 0x1464bc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464C0u; }
        if (ctx->pc != 0x1464C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464C0u; }
        if (ctx->pc != 0x1464C0u) { return; }
    }
    ctx->pc = 0x1464C0u;
label_1464c0:
    // 0x1464c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464c4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464C4u;
    SET_GPR_U32(ctx, 31, 0x1464CCu);
    ctx->pc = 0x1464C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464C4u;
            // 0x1464c8: 0x24050016  addiu       $a1, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464CCu; }
        if (ctx->pc != 0x1464CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464CCu; }
        if (ctx->pc != 0x1464CCu) { return; }
    }
    ctx->pc = 0x1464CCu;
label_1464cc:
    // 0x1464cc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464d0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1464D0u;
    SET_GPR_U32(ctx, 31, 0x1464D8u);
    ctx->pc = 0x1464D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464D0u;
            // 0x1464d4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464D8u; }
        if (ctx->pc != 0x1464D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1464D8u; }
        if (ctx->pc != 0x1464D8u) { return; }
    }
    ctx->pc = 0x1464D8u;
label_1464d8:
    // 0x1464d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1464d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1464dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1464dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1464e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1464e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1464e4: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x1464e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1464e8: 0x805167a  j           func_1459E8
    ctx->pc = 0x1464E8u;
    ctx->pc = 0x1464ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1464E8u;
            // 0x1464ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001459E8_0x1459e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1464F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
