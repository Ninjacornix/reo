#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001876C8
// Address: 0x1876c8 - 0x187798
void sub_001876C8_0x1876c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001876C8_0x1876c8");
#endif

    switch (ctx->pc) {
        case 0x1876fcu: goto label_1876fc;
        case 0x187708u: goto label_187708;
        case 0x187770u: goto label_187770;
        default: break;
    }

    ctx->pc = 0x1876c8u;

    // 0x1876c8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1876c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1876cc: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1876ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1876d0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1876d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1876d4: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x1876d4u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x1876d8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1876d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1876dc: 0x2450d980  addiu       $s0, $v0, -0x2680
    ctx->pc = 0x1876dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957440));
    // 0x1876e0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1876e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1876e4: 0x2671fd20  addiu       $s1, $s3, -0x2E0
    ctx->pc = 0x1876e4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966560));
    // 0x1876e8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1876e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1876ec: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1876ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1876f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1876f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1876f4: 0xc062230  jal         func_1888C0
    ctx->pc = 0x1876F4u;
    SET_GPR_U32(ctx, 31, 0x1876FCu);
    ctx->pc = 0x1876F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1876F4u;
            // 0x1876f8: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888C0u;
    if (runtime->hasFunction(0x1888C0u)) {
        auto targetFn = runtime->lookupFunction(0x1888C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1876FCu; }
        if (ctx->pc != 0x1876FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888C0_0x1888c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1876FCu; }
        if (ctx->pc != 0x1876FCu) { return; }
    }
    ctx->pc = 0x1876FCu;
label_1876fc:
    // 0x1876fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1876fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187700: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x187700u;
    SET_GPR_U32(ctx, 31, 0x187708u);
    ctx->pc = 0x187704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187700u;
            // 0x187704: 0x260500ff  addiu       $a1, $s0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187708u; }
        if (ctx->pc != 0x187708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187708u; }
        if (ctx->pc != 0x187708u) { return; }
    }
    ctx->pc = 0x187708u;
label_187708:
    // 0x187708: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x187708u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18770c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x18770cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x187710: 0x44102a  slt         $v0, $v0, $a0
    ctx->pc = 0x187710u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x187714: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x187714u;
    {
        const bool branch_taken_0x187714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187714u;
            // 0x187718: 0x26030080  addiu       $v1, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187714) {
            ctx->pc = 0x187738u;
            goto label_187738;
        }
    }
    ctx->pc = 0x18771Cu;
    // 0x18771c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x18771cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x187720: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x187720u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x187724: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x187724u;
    {
        const bool branch_taken_0x187724 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x187724) {
            ctx->pc = 0x187728u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187724u;
            // 0x187728: 0x2665fd20  addiu       $a1, $s3, -0x2E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966560));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187740u;
            goto label_187740;
        }
    }
    ctx->pc = 0x18772Cu;
    // 0x18772c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x18772Cu;
    {
        const bool branch_taken_0x18772c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18772Cu;
            // 0x187730: 0xae240000  sw          $a0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18772c) {
            ctx->pc = 0x187778u;
            goto label_187778;
        }
    }
    ctx->pc = 0x187734u;
    // 0x187734: 0x0  nop
    ctx->pc = 0x187734u;
    // NOP
label_187738:
    // 0x187738: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x187738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18773c: 0x2665fd20  addiu       $a1, $s3, -0x2E0
    ctx->pc = 0x18773cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966560));
label_187740:
    // 0x187740: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x187740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x187744: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x187744u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x187748: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x187748u;
    {
        const bool branch_taken_0x187748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18774Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187748u;
            // 0x18774c: 0x83102a  slt         $v0, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x187748) {
            ctx->pc = 0x187768u;
            goto label_187768;
        }
    }
    ctx->pc = 0x187750u;
    // 0x187750: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x187750u;
    {
        const bool branch_taken_0x187750 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187750u;
            // 0x187754: 0x3c020029  lui         $v0, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187750) {
            ctx->pc = 0x187768u;
            goto label_187768;
        }
    }
    ctx->pc = 0x187758u;
    // 0x187758: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x187758u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x18775c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18775Cu;
    {
        const bool branch_taken_0x18775c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18775Cu;
            // 0x187760: 0x2442da00  addiu       $v0, $v0, -0x2600 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957568));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18775c) {
            ctx->pc = 0x18777Cu;
            goto label_18777c;
        }
    }
    ctx->pc = 0x187764u;
    // 0x187764: 0x0  nop
    ctx->pc = 0x187764u;
    // NOP
label_187768:
    // 0x187768: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x187768u;
    SET_GPR_U32(ctx, 31, 0x187770u);
    ctx->pc = 0x18776Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187768u;
            // 0x18776c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187770u; }
        if (ctx->pc != 0x187770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187770u; }
        if (ctx->pc != 0x187770u) { return; }
    }
    ctx->pc = 0x187770u;
label_187770:
    // 0x187770: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x187770u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x187774: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x187774u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_187778:
    // 0x187778: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x187778u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18777c:
    // 0x18777c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18777cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x187780: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x187780u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x187784: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x187784u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187788: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x187788u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x18778c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18778cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x187790: 0x3e00008  jr          $ra
    ctx->pc = 0x187790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187790u;
            // 0x187794: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1876FCu: goto label_1876fc;
            case 0x187708u: goto label_187708;
            case 0x187738u: goto label_187738;
            case 0x187740u: goto label_187740;
            case 0x187768u: goto label_187768;
            case 0x187770u: goto label_187770;
            case 0x187778u: goto label_187778;
            case 0x18777Cu: goto label_18777c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187798u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
