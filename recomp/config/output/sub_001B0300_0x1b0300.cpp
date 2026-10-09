#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0300
// Address: 0x1b0300 - 0x1b05b0
void sub_001B0300_0x1b0300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0300_0x1b0300");
#endif

    switch (ctx->pc) {
        case 0x1b0368u: goto label_1b0368;
        case 0x1b03e8u: goto label_1b03e8;
        case 0x1b0434u: goto label_1b0434;
        case 0x1b0448u: goto label_1b0448;
        case 0x1b0480u: goto label_1b0480;
        case 0x1b04e0u: goto label_1b04e0;
        case 0x1b0524u: goto label_1b0524;
        case 0x1b053cu: goto label_1b053c;
        case 0x1b0540u: goto label_1b0540;
        case 0x1b0548u: goto label_1b0548;
        case 0x1b0554u: goto label_1b0554;
        case 0x1b0560u: goto label_1b0560;
        case 0x1b056cu: goto label_1b056c;
        case 0x1b0578u: goto label_1b0578;
        case 0x1b0584u: goto label_1b0584;
        case 0x1b0590u: goto label_1b0590;
        default: break;
    }

    ctx->pc = 0x1b0300u;

    // 0x1b0300: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0300u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0304: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0304u;
            // 0x1b0308: 0x902243f2  lbu         $v0, 0x43F2($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17394)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B030Cu;
    // 0x1b030c: 0x0  nop
    ctx->pc = 0x1b030cu;
    // NOP
    // 0x1b0310: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0310u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0314: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0318: 0x802343fb  lb          $v1, 0x43FB($at)
    ctx->pc = 0x1b0318u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17403)));
    // 0x1b031c: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B031Cu;
    {
        const bool branch_taken_0x1b031c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B0320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B031Cu;
            // 0x1b0320: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b031c) {
            ctx->pc = 0x1B0334u;
            goto label_1b0334;
        }
    }
    ctx->pc = 0x1B0324u;
    // 0x1b0324: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b0324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b0328: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0328u;
    {
        const bool branch_taken_0x1b0328 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B032Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0328u;
            // 0x1b032c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0328) {
            ctx->pc = 0x1B0334u;
            goto label_1b0334;
        }
    }
    ctx->pc = 0x1B0330u;
    // 0x1b0330: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b0334:
    // 0x1b0334: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0334u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B033Cu;
    // 0x1b033c: 0x0  nop
    ctx->pc = 0x1b033cu;
    // NOP
    // 0x1b0340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0344: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0348: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0348u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b034c: 0x90820002  lbu         $v0, 0x2($a0)
    ctx->pc = 0x1b034cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b0350: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0350u;
    {
        const bool branch_taken_0x1b0350 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0350u;
            // 0x1b0354: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0350) {
            ctx->pc = 0x1B0360u;
            goto label_1b0360;
        }
    }
    ctx->pc = 0x1B0358u;
    // 0x1b0358: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1B0358u;
    {
        const bool branch_taken_0x1b0358 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0358u;
            // 0x1b035c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0358) {
            ctx->pc = 0x1B03A4u;
            goto label_1b03a4;
        }
    }
    ctx->pc = 0x1B0360u;
label_1b0360:
    // 0x1b0360: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B0360u;
    SET_GPR_U32(ctx, 31, 0x1B0368u);
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0368u; }
        if (ctx->pc != 0x1B0368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0368u; }
        if (ctx->pc != 0x1B0368u) { return; }
    }
    ctx->pc = 0x1B0368u;
label_1b0368:
    // 0x1b0368: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b0368u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b036c: 0x14440006  bne         $v0, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B036Cu;
    {
        const bool branch_taken_0x1b036c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1B0370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B036Cu;
            // 0x1b0370: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b036c) {
            ctx->pc = 0x1B0388u;
            goto label_1b0388;
        }
    }
    ctx->pc = 0x1B0374u;
    // 0x1b0374: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1b0374u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b0378: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B0378u;
    {
        const bool branch_taken_0x1b0378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B037Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0378u;
            // 0x1b037c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0378) {
            ctx->pc = 0x1B03A4u;
            goto label_1b03a4;
        }
    }
    ctx->pc = 0x1B0380u;
    // 0x1b0380: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B0380u;
    {
        const bool branch_taken_0x1b0380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0380u;
            // 0x1b0384: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0380) {
            ctx->pc = 0x1B03A4u;
            goto label_1b03a4;
        }
    }
    ctx->pc = 0x1B0388u;
label_1b0388:
    // 0x1b0388: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1b0388u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b038c: 0x9023aded  lbu         $v1, -0x5213($at)
    ctx->pc = 0x1b038cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b0390: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0390u;
    {
        const bool branch_taken_0x1b0390 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B0394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0390u;
            // 0x1b0394: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0390) {
            ctx->pc = 0x1B03A0u;
            goto label_1b03a0;
        }
    }
    ctx->pc = 0x1B0398u;
    // 0x1b0398: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0398u;
    {
        const bool branch_taken_0x1b0398 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B039Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0398u;
            // 0x1b039c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0398) {
            ctx->pc = 0x1B03A8u;
            goto label_1b03a8;
        }
    }
    ctx->pc = 0x1B03A0u;
label_1b03a0:
    // 0x1b03a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b03a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b03a4:
    // 0x1b03a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b03a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b03a8:
    // 0x1b03a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b03a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b03ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1B03ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B03B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03ACu;
            // 0x1b03b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B03B4u;
    // 0x1b03b4: 0x0  nop
    ctx->pc = 0x1b03b4u;
    // NOP
    // 0x1b03b8: 0x0  nop
    ctx->pc = 0x1b03b8u;
    // NOP
    // 0x1b03bc: 0x0  nop
    ctx->pc = 0x1b03bcu;
    // NOP
    // 0x1b03c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b03c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b03c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b03c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b03c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b03c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b03cc: 0x90820002  lbu         $v0, 0x2($a0)
    ctx->pc = 0x1b03ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b03d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B03D0u;
    {
        const bool branch_taken_0x1b03d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B03D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03D0u;
            // 0x1b03d4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b03d0) {
            ctx->pc = 0x1B03E0u;
            goto label_1b03e0;
        }
    }
    ctx->pc = 0x1B03D8u;
    // 0x1b03d8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B03D8u;
    {
        const bool branch_taken_0x1b03d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B03DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03D8u;
            // 0x1b03dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b03d8) {
            ctx->pc = 0x1B040Cu;
            goto label_1b040c;
        }
    }
    ctx->pc = 0x1B03E0u;
label_1b03e0:
    // 0x1b03e0: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B03E0u;
    SET_GPR_U32(ctx, 31, 0x1B03E8u);
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B03E8u; }
        if (ctx->pc != 0x1B03E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B03E8u; }
        if (ctx->pc != 0x1B03E8u) { return; }
    }
    ctx->pc = 0x1B03E8u;
label_1b03e8:
    // 0x1b03e8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b03e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b03ec: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B03ECu;
    {
        const bool branch_taken_0x1b03ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b03ec) {
            ctx->pc = 0x1B0408u;
            goto label_1b0408;
        }
    }
    ctx->pc = 0x1B03F4u;
    // 0x1b03f4: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1b03f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b03f8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B03F8u;
    {
        const bool branch_taken_0x1b03f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B03FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03F8u;
            // 0x1b03fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b03f8) {
            ctx->pc = 0x1B040Cu;
            goto label_1b040c;
        }
    }
    ctx->pc = 0x1B0400u;
    // 0x1b0400: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0400u;
    {
        const bool branch_taken_0x1b0400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0400u;
            // 0x1b0404: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0400) {
            ctx->pc = 0x1B040Cu;
            goto label_1b040c;
        }
    }
    ctx->pc = 0x1B0408u;
label_1b0408:
    // 0x1b0408: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b0408u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b040c:
    // 0x1b040c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b040cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0410: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0410u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0414: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0414u;
            // 0x1b0418: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B041Cu;
    // 0x1b041c: 0x0  nop
    ctx->pc = 0x1b041cu;
    // NOP
    // 0x1b0420: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b0420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b0424: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b0424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b0428: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b0428u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b042c: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B042Cu;
    SET_GPR_U32(ctx, 31, 0x1B0434u);
    ctx->pc = 0x1B0430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B042Cu;
            // 0x1b0430: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0434u; }
        if (ctx->pc != 0x1B0434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0434u; }
        if (ctx->pc != 0x1B0434u) { return; }
    }
    ctx->pc = 0x1B0434u;
label_1b0434:
    // 0x1b0434: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0438: 0x1443001a  bne         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B0438u;
    {
        const bool branch_taken_0x1b0438 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B043Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0438u;
            // 0x1b043c: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0438) {
            ctx->pc = 0x1B04A4u;
            goto label_1b04a4;
        }
    }
    ctx->pc = 0x1B0440u;
    // 0x1b0440: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B0440u;
    {
        const bool branch_taken_0x1b0440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0440u;
            // 0x1b0444: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0440) {
            ctx->pc = 0x1B0488u;
            goto label_1b0488;
        }
    }
    ctx->pc = 0x1B0448u;
label_1b0448:
    // 0x1b0448: 0x2463eef0  addiu       $v1, $v1, -0x1110
    ctx->pc = 0x1b0448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294962928));
    // 0x1b044c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1b044cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b0450: 0x24706d35  addiu       $s0, $v1, 0x6D35
    ctx->pc = 0x1b0450u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 27957));
    // 0x1b0454: 0x90636d35  lbu         $v1, 0x6D35($v1)
    ctx->pc = 0x1b0454u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 27957)));
    // 0x1b0458: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B0458u;
    {
        const bool branch_taken_0x1b0458 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0458u;
            // 0x1b045c: 0x111900  sll         $v1, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0458) {
            ctx->pc = 0x1B0484u;
            goto label_1b0484;
        }
    }
    ctx->pc = 0x1B0460u;
    // 0x1b0460: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1b0460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1b0464: 0x712023  subu        $a0, $v1, $s1
    ctx->pc = 0x1b0464u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b0468: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1b0468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1b046c: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x1b046cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b0470: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b0470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b0474: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1b0474u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1b0478: 0xc15c1d4  jal         func_570750
    ctx->pc = 0x1B0478u;
    SET_GPR_U32(ctx, 31, 0x1B0480u);
    ctx->pc = 0x1B047Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0478u;
            // 0x1b047c: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x570750u;
    {
        auto targetFn = runtime->lookupFunction(0x570750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0480u; }
        if (ctx->pc != 0x1B0480u) { return; }
    }
    ctx->pc = 0x1B0480u;
label_1b0480:
    // 0x1b0480: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1b0480u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1b0484:
    // 0x1b0484: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b0484u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b0488:
    // 0x1b0488: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b0488u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b048c: 0x8c23aea0  lw          $v1, -0x5160($at)
    ctx->pc = 0x1b048cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294946464)));
    // 0x1b0490: 0x223182b  sltu        $v1, $s1, $v1
    ctx->pc = 0x1b0490u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b0494: 0x1460ffec  bnez        $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1B0494u;
    {
        const bool branch_taken_0x1b0494 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B0498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0494u;
            // 0x1b0498: 0x3c03004a  lui         $v1, 0x4A (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0494) {
            ctx->pc = 0x1B0448u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0448;
        }
    }
    ctx->pc = 0x1B049Cu;
    // 0x1b049c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1B049Cu;
    {
        const bool branch_taken_0x1b049c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B04A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B049Cu;
            // 0x1b04a0: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b049c) {
            ctx->pc = 0x1B04FCu;
            goto label_1b04fc;
        }
    }
    ctx->pc = 0x1B04A4u;
label_1b04a4:
    // 0x1b04a4: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1b04a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1b04a8: 0x9024aded  lbu         $a0, -0x5213($at)
    ctx->pc = 0x1b04a8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b04ac: 0x24635c25  addiu       $v1, $v1, 0x5C25
    ctx->pc = 0x1b04acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23589));
    // 0x1b04b0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b04b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b04b4: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1b04b4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b04b8: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1B04B8u;
    {
        const bool branch_taken_0x1b04b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B04BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B04B8u;
            // 0x1b04bc: 0x41900  sll         $v1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b04b8) {
            ctx->pc = 0x1B04F8u;
            goto label_1b04f8;
        }
    }
    ctx->pc = 0x1B04C0u;
    // 0x1b04c0: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1b04c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1b04c4: 0x642023  subu        $a0, $v1, $a0
    ctx->pc = 0x1b04c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b04c8: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1b04c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1b04cc: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x1b04ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b04d0: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b04d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b04d4: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1b04d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1b04d8: 0xc15c1d4  jal         func_570750
    ctx->pc = 0x1B04D8u;
    SET_GPR_U32(ctx, 31, 0x1B04E0u);
    ctx->pc = 0x1B04DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B04D8u;
            // 0x1b04dc: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x570750u;
    {
        auto targetFn = runtime->lookupFunction(0x570750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B04E0u; }
        if (ctx->pc != 0x1B04E0u) { return; }
    }
    ctx->pc = 0x1B04E0u;
label_1b04e0:
    // 0x1b04e0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b04e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b04e4: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1b04e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1b04e8: 0x9024aded  lbu         $a0, -0x5213($at)
    ctx->pc = 0x1b04e8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b04ec: 0x24635c25  addiu       $v1, $v1, 0x5C25
    ctx->pc = 0x1b04ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23589));
    // 0x1b04f0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b04f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b04f4: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1b04f4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1b04f8:
    // 0x1b04f8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b04f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1b04fc:
    // 0x1b04fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b04fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0500: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0500u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0504: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0504u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0504u;
            // 0x1b0508: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B050Cu;
    // 0x1b050c: 0x0  nop
    ctx->pc = 0x1b050cu;
    // NOP
    // 0x1b0510: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b0510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b0514: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b0514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0518: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b051c: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1B051Cu;
    SET_GPR_U32(ctx, 31, 0x1B0524u);
    ctx->pc = 0x1B0520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B051Cu;
            // 0x1b0520: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0524u; }
        if (ctx->pc != 0x1B0524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0524u; }
        if (ctx->pc != 0x1B0524u) { return; }
    }
    ctx->pc = 0x1B0524u;
label_1b0524:
    // 0x1b0524: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1b0524u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1b0528: 0x8fa3002c  lw          $v1, 0x2C($sp)
    ctx->pc = 0x1b0528u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1b052c: 0x1060001c  beqz        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1B052Cu;
    {
        const bool branch_taken_0x1b052c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b052c) {
            ctx->pc = 0x1B05A0u;
            goto label_1b05a0;
        }
    }
    ctx->pc = 0x1B0534u;
    // 0x1b0534: 0xc063594  jal         func_18D650
    ctx->pc = 0x1B0534u;
    SET_GPR_U32(ctx, 31, 0x1B053Cu);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B053Cu; }
        if (ctx->pc != 0x1B053Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B053Cu; }
        if (ctx->pc != 0x1B053Cu) { return; }
    }
    ctx->pc = 0x1B053Cu;
label_1b053c:
    // 0x1b053c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b053cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b0540:
    // 0x1b0540: 0xc06eabc  jal         func_1BAAF0
    ctx->pc = 0x1B0540u;
    SET_GPR_U32(ctx, 31, 0x1B0548u);
    ctx->pc = 0x1B0544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0540u;
            // 0x1b0544: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BAAF0u;
    if (runtime->hasFunction(0x1BAAF0u)) {
        auto targetFn = runtime->lookupFunction(0x1BAAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0548u; }
        if (ctx->pc != 0x1B0548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAAF0_0x1baaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0548u; }
        if (ctx->pc != 0x1B0548u) { return; }
    }
    ctx->pc = 0x1B0548u;
label_1b0548:
    // 0x1b0548: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1b0548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b054c: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1B054Cu;
    SET_GPR_U32(ctx, 31, 0x1B0554u);
    ctx->pc = 0x1B0550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B054Cu;
            // 0x1b0550: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0554u; }
        if (ctx->pc != 0x1B0554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0554u; }
        if (ctx->pc != 0x1B0554u) { return; }
    }
    ctx->pc = 0x1B0554u;
label_1b0554:
    // 0x1b0554: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1b0554u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1b0558: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B0558u;
    SET_GPR_U32(ctx, 31, 0x1B0560u);
    ctx->pc = 0x1B055Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0558u;
            // 0x1b055c: 0x3c050001  lui         $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0560u; }
        if (ctx->pc != 0x1B0560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0560u; }
        if (ctx->pc != 0x1B0560u) { return; }
    }
    ctx->pc = 0x1B0560u;
label_1b0560:
    // 0x1b0560: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b0560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b0564: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B0564u;
    SET_GPR_U32(ctx, 31, 0x1B056Cu);
    ctx->pc = 0x1B0568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0564u;
            // 0x1b0568: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B056Cu; }
        if (ctx->pc != 0x1B056Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B056Cu; }
        if (ctx->pc != 0x1B056Cu) { return; }
    }
    ctx->pc = 0x1B056Cu;
label_1b056c:
    // 0x1b056c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b056cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0570: 0xc0675c8  jal         func_19D720
    ctx->pc = 0x1B0570u;
    SET_GPR_U32(ctx, 31, 0x1B0578u);
    ctx->pc = 0x1B0574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0570u;
            // 0x1b0574: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D720u;
    if (runtime->hasFunction(0x19D720u)) {
        auto targetFn = runtime->lookupFunction(0x19D720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0578u; }
        if (ctx->pc != 0x1B0578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D720_0x19d720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0578u; }
        if (ctx->pc != 0x1B0578u) { return; }
    }
    ctx->pc = 0x1B0578u;
label_1b0578:
    // 0x1b0578: 0x8fa5002c  lw          $a1, 0x2C($sp)
    ctx->pc = 0x1b0578u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1b057c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B057Cu;
    SET_GPR_U32(ctx, 31, 0x1B0584u);
    ctx->pc = 0x1B0580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B057Cu;
            // 0x1b0580: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0584u; }
        if (ctx->pc != 0x1B0584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0584u; }
        if (ctx->pc != 0x1B0584u) { return; }
    }
    ctx->pc = 0x1B0584u;
label_1b0584:
    // 0x1b0584: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1b0584u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1b0588: 0xc06ae18  jal         func_1AB860
    ctx->pc = 0x1B0588u;
    SET_GPR_U32(ctx, 31, 0x1B0590u);
    ctx->pc = 0x1B058Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0588u;
            // 0x1b058c: 0x24844380  addiu       $a0, $a0, 0x4380 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB860u;
    if (runtime->hasFunction(0x1AB860u)) {
        auto targetFn = runtime->lookupFunction(0x1AB860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0590u; }
        if (ctx->pc != 0x1B0590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB860_0x1ab860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0590u; }
        if (ctx->pc != 0x1B0590u) { return; }
    }
    ctx->pc = 0x1B0590u;
label_1b0590:
    // 0x1b0590: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b0590u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b0594: 0x2a030003  slti        $v1, $s0, 0x3
    ctx->pc = 0x1b0594u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1b0598: 0x1460ffe9  bnez        $v1, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1B0598u;
    {
        const bool branch_taken_0x1b0598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b0598) {
            ctx->pc = 0x1B0540u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0540;
        }
    }
    ctx->pc = 0x1B05A0u;
label_1b05a0:
    // 0x1b05a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b05a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b05a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b05a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b05a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B05A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B05ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05A8u;
            // 0x1b05ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            case 0x1B0434u: goto label_1b0434;
            case 0x1B0448u: goto label_1b0448;
            case 0x1B0480u: goto label_1b0480;
            case 0x1B0484u: goto label_1b0484;
            case 0x1B0488u: goto label_1b0488;
            case 0x1B04A4u: goto label_1b04a4;
            case 0x1B04E0u: goto label_1b04e0;
            case 0x1B04F8u: goto label_1b04f8;
            case 0x1B04FCu: goto label_1b04fc;
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B05B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
