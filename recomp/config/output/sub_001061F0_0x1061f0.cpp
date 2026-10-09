#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001061F0
// Address: 0x1061f0 - 0x106358
void sub_001061F0_0x1061f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001061F0_0x1061f0");
#endif

    switch (ctx->pc) {
        case 0x10621cu: goto label_10621c;
        case 0x106290u: goto label_106290;
        case 0x1062b8u: goto label_1062b8;
        case 0x1062e0u: goto label_1062e0;
        default: break;
    }

    ctx->pc = 0x1061f0u;

    // 0x1061f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1061f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1061f4: 0x3c020037  lui         $v0, 0x37
    ctx->pc = 0x1061f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)55 << 16));
    // 0x1061f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1061f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1061fc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1061fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106200: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106204: 0x2451f0dc  addiu       $s1, $v0, -0xF24
    ctx->pc = 0x106204u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963420));
    // 0x106208: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x106208u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10620c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x10620cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106210: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x106210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x106214: 0xc045376  jal         func_114DD8
    ctx->pc = 0x106214u;
    SET_GPR_U32(ctx, 31, 0x10621Cu);
    ctx->pc = 0x106218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106214u;
            // 0x106218: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114DD8u;
    if (runtime->hasFunction(0x114DD8u)) {
        auto targetFn = runtime->lookupFunction(0x114DD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10621Cu; }
        if (ctx->pc != 0x10621Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114DD8_0x114dd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10621Cu; }
        if (ctx->pc != 0x10621Cu) { return; }
    }
    ctx->pc = 0x10621Cu;
label_10621c:
    // 0x10621c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10621cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106220: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x106220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x106224: 0x54640005  bnel        $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x106224u;
    {
        const bool branch_taken_0x106224 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x106224) {
            ctx->pc = 0x106228u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106224u;
            // 0x106228: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10623Cu;
            goto label_10623c;
        }
    }
    ctx->pc = 0x10622Cu;
    // 0x10622c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x10622cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x106230: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x106230u;
    {
        const bool branch_taken_0x106230 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x106230) {
            ctx->pc = 0x106234u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106230u;
            // 0x106234: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106238u;
            goto label_106238;
        }
    }
    ctx->pc = 0x106238u;
label_106238:
    // 0x106238: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106238u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_10623c:
    // 0x10623c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10623cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106240: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x106240u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106244: 0x3e00008  jr          $ra
    ctx->pc = 0x106244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106244u;
            // 0x106248: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10621Cu: goto label_10621c;
            case 0x106238u: goto label_106238;
            case 0x10623Cu: goto label_10623c;
            case 0x106280u: goto label_106280;
            case 0x106290u: goto label_106290;
            case 0x106294u: goto label_106294;
            case 0x1062B0u: goto label_1062b0;
            case 0x1062B8u: goto label_1062b8;
            case 0x1062D0u: goto label_1062d0;
            case 0x1062E0u: goto label_1062e0;
            case 0x1062F4u: goto label_1062f4;
            case 0x106320u: goto label_106320;
            case 0x106340u: goto label_106340;
            case 0x106344u: goto label_106344;
            case 0x106348u: goto label_106348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10624Cu;
    // 0x10624c: 0x0  nop
    ctx->pc = 0x10624cu;
    // NOP
    // 0x106250: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x106250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x106254: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106258: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x106258u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10625c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10625cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x106260: 0x8e030054  lw          $v1, 0x54($s0)
    ctx->pc = 0x106260u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x106264: 0x54600006  bnel        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x106264u;
    {
        const bool branch_taken_0x106264 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x106264) {
            ctx->pc = 0x106268u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106264u;
            // 0x106268: 0x8c620038  lw          $v0, 0x38($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106280u;
            goto label_106280;
        }
    }
    ctx->pc = 0x10626Cu;
    // 0x10626c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10626cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106270: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x106270u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106274: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x106274u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x106278: 0x8c620038  lw          $v0, 0x38($v1)
    ctx->pc = 0x106278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
    // 0x10627c: 0x0  nop
    ctx->pc = 0x10627cu;
    // NOP
label_106280:
    // 0x106280: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x106280u;
    {
        const bool branch_taken_0x106280 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106280) {
            ctx->pc = 0x106284u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106280u;
            // 0x106284: 0x8e020028  lw          $v0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106294u;
            goto label_106294;
        }
    }
    ctx->pc = 0x106288u;
    // 0x106288: 0xc041544  jal         func_105510
    ctx->pc = 0x106288u;
    SET_GPR_U32(ctx, 31, 0x106290u);
    ctx->pc = 0x10628Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106288u;
            // 0x10628c: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106290u; }
        if (ctx->pc != 0x106290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106290u; }
        if (ctx->pc != 0x106290u) { return; }
    }
    ctx->pc = 0x106290u;
label_106290:
    // 0x106290: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x106290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
label_106294:
    // 0x106294: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x106294u;
    {
        const bool branch_taken_0x106294 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106294u;
            // 0x106298: 0x2403001d  addiu       $v1, $zero, 0x1D (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106294) {
            ctx->pc = 0x1062B0u;
            goto label_1062b0;
        }
    }
    ctx->pc = 0x10629Cu;
    // 0x10629c: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10629cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x1062a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1062a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1062a4: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1062A4u;
    {
        const bool branch_taken_0x1062a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1062A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1062A4u;
            // 0x1062a8: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1062a4) {
            ctx->pc = 0x106344u;
            goto label_106344;
        }
    }
    ctx->pc = 0x1062ACu;
    // 0x1062ac: 0x0  nop
    ctx->pc = 0x1062acu;
    // NOP
label_1062b0:
    // 0x1062b0: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x1062B0u;
    SET_GPR_U32(ctx, 31, 0x1062B8u);
    ctx->pc = 0x1062B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1062B0u;
            // 0x1062b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1062B8u; }
        if (ctx->pc != 0x1062B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1062B8u; }
        if (ctx->pc != 0x1062B8u) { return; }
    }
    ctx->pc = 0x1062B8u;
label_1062b8:
    // 0x1062b8: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x1062b8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1062bc: 0x30621000  andi        $v0, $v1, 0x1000
    ctx->pc = 0x1062bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4096);
    // 0x1062c0: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1062C0u;
    {
        const bool branch_taken_0x1062c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1062c0) {
            ctx->pc = 0x1062C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1062C0u;
            // 0x1062c4: 0x8e020028  lw          $v0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1062D0u;
            goto label_1062d0;
        }
    }
    ctx->pc = 0x1062C8u;
    // 0x1062c8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1062C8u;
    {
        const bool branch_taken_0x1062c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1062CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1062C8u;
            // 0x1062cc: 0x8e050050  lw          $a1, 0x50($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1062c8) {
            ctx->pc = 0x1062F4u;
            goto label_1062f4;
        }
    }
    ctx->pc = 0x1062D0u;
label_1062d0:
    // 0x1062d0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1062d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1062d4: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x1062d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1062d8: 0x40f809  jalr        $v0
    ctx->pc = 0x1062D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1062E0u);
        ctx->pc = 0x1062DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1062D8u;
            // 0x1062dc: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1062E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10621Cu: goto label_10621c;
            case 0x106238u: goto label_106238;
            case 0x10623Cu: goto label_10623c;
            case 0x106280u: goto label_106280;
            case 0x106290u: goto label_106290;
            case 0x106294u: goto label_106294;
            case 0x1062B0u: goto label_1062b0;
            case 0x1062B8u: goto label_1062b8;
            case 0x1062D0u: goto label_1062d0;
            case 0x1062E0u: goto label_1062e0;
            case 0x1062F4u: goto label_1062f4;
            case 0x106320u: goto label_106320;
            case 0x106340u: goto label_106340;
            case 0x106344u: goto label_106344;
            case 0x106348u: goto label_106348;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1062E0u; }
            if (ctx->pc != 0x1062E0u) { return; }
        }
        }
    }
    ctx->pc = 0x1062E0u;
label_1062e0:
    // 0x1062e0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1062e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1062e4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1062e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1062e8: 0x50a30017  beql        $a1, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1062E8u;
    {
        const bool branch_taken_0x1062e8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1062e8) {
            ctx->pc = 0x1062ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1062E8u;
            // 0x1062ec: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106348u;
            goto label_106348;
        }
    }
    ctx->pc = 0x1062F0u;
    // 0x1062f0: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x1062f0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_1062f4:
    // 0x1062f4: 0x30620004  andi        $v0, $v1, 0x4
    ctx->pc = 0x1062f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
    // 0x1062f8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1062F8u;
    {
        const bool branch_taken_0x1062f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1062FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1062F8u;
            // 0x1062fc: 0x30620008  andi        $v0, $v1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1062f8) {
            ctx->pc = 0x106320u;
            goto label_106320;
        }
    }
    ctx->pc = 0x106300u;
    // 0x106300: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x106300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x106304: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x106304u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x106308: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x106308u;
    {
        const bool branch_taken_0x106308 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10630Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106308u;
            // 0x10630c: 0xa2282f  dsubu       $a1, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106308) {
            ctx->pc = 0x106340u;
            goto label_106340;
        }
    }
    ctx->pc = 0x106310u;
    // 0x106310: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x106310u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x106314: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x106314u;
    {
        const bool branch_taken_0x106314 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106314u;
            // 0x106318: 0xa2282f  dsubu       $a1, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106314) {
            ctx->pc = 0x106340u;
            goto label_106340;
        }
    }
    ctx->pc = 0x10631Cu;
    // 0x10631c: 0x0  nop
    ctx->pc = 0x10631cu;
    // NOP
label_106320:
    // 0x106320: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x106320u;
    {
        const bool branch_taken_0x106320 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106320u;
            // 0x106324: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106320) {
            ctx->pc = 0x106344u;
            goto label_106344;
        }
    }
    ctx->pc = 0x106328u;
    // 0x106328: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x106328u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x10632c: 0x50600006  beql        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10632Cu;
    {
        const bool branch_taken_0x10632c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x10632c) {
            ctx->pc = 0x106330u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10632Cu;
            // 0x106330: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106348u;
            goto label_106348;
        }
    }
    ctx->pc = 0x106334u;
    // 0x106334: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x106334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x106338: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x106338u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10633c: 0xa2282d  daddu       $a1, $a1, $v0
    ctx->pc = 0x10633cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 2));
label_106340:
    // 0x106340: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x106340u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_106344:
    // 0x106344: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106344u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_106348:
    // 0x106348: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x106348u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10634c: 0x3e00008  jr          $ra
    ctx->pc = 0x10634Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10634Cu;
            // 0x106350: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10621Cu: goto label_10621c;
            case 0x106238u: goto label_106238;
            case 0x10623Cu: goto label_10623c;
            case 0x106280u: goto label_106280;
            case 0x106290u: goto label_106290;
            case 0x106294u: goto label_106294;
            case 0x1062B0u: goto label_1062b0;
            case 0x1062B8u: goto label_1062b8;
            case 0x1062D0u: goto label_1062d0;
            case 0x1062E0u: goto label_1062e0;
            case 0x1062F4u: goto label_1062f4;
            case 0x106320u: goto label_106320;
            case 0x106340u: goto label_106340;
            case 0x106344u: goto label_106344;
            case 0x106348u: goto label_106348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106354u;
    // 0x106354: 0x0  nop
    ctx->pc = 0x106354u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
