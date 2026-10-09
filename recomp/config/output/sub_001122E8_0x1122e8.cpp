#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001122E8
// Address: 0x1122e8 - 0x1123a0
void sub_001122E8_0x1122e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001122E8_0x1122e8");
#endif

    switch (ctx->pc) {
        case 0x112368u: goto label_112368;
        case 0x112394u: goto label_112394;
        default: break;
    }

    ctx->pc = 0x1122e8u;

    // 0x1122e8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1122e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1122ec: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1122ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1122f0: 0x41fc2  srl         $v1, $a0, 31
    ctx->pc = 0x1122f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 31));
    // 0x1122f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1122f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1122f8: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1122f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1122fc: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1122FCu;
    {
        const bool branch_taken_0x1122fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x112300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1122FCu;
            // 0x112300: 0xafa30004  sw          $v1, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1122fc) {
            ctx->pc = 0x112310u;
            goto label_112310;
        }
    }
    ctx->pc = 0x112304u;
    // 0x112304: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x112304u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x112308: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x112308u;
    {
        const bool branch_taken_0x112308 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11230Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112308u;
            // 0x11230c: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112308) {
            ctx->pc = 0x11238Cu;
            goto label_11238c;
        }
    }
    ctx->pc = 0x112310u;
label_112310:
    // 0x112310: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x112310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x112314: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x112314u;
    {
        const bool branch_taken_0x112314 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x112318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112314u;
            // 0x112318: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112314) {
            ctx->pc = 0x112340u;
            goto label_112340;
        }
    }
    ctx->pc = 0x11231Cu;
    // 0x11231c: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x11231cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x112320: 0x3402c1e0  ori         $v0, $zero, 0xC1E0
    ctx->pc = 0x112320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49632);
    // 0x112324: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x112324u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x112328: 0x1083001b  beq         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x112328u;
    {
        const bool branch_taken_0x112328 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x11232Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112328u;
            // 0x11232c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112328) {
            ctx->pc = 0x112398u;
            goto label_112398;
        }
    }
    ctx->pc = 0x112330u;
    // 0x112330: 0x41023  negu        $v0, $a0
    ctx->pc = 0x112330u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x112334: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x112334u;
    {
        const bool branch_taken_0x112334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112334u;
            // 0x112338: 0xffa20010  sd          $v0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112334) {
            ctx->pc = 0x112344u;
            goto label_112344;
        }
    }
    ctx->pc = 0x11233Cu;
    // 0x11233c: 0x0  nop
    ctx->pc = 0x11233cu;
    // NOP
label_112340:
    // 0x112340: 0xffa40010  sd          $a0, 0x10($sp)
    ctx->pc = 0x112340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 4));
label_112344:
    // 0x112344: 0xdfa40010  ld          $a0, 0x10($sp)
    ctx->pc = 0x112344u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112348: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x112348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11234c: 0x2113a  dsrl        $v0, $v0, 4
    ctx->pc = 0x11234cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 4);
    // 0x112350: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x112350u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x112354: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x112354u;
    {
        const bool branch_taken_0x112354 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x112358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112354u;
            // 0x112358: 0x8fa50008  lw          $a1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112354) {
            ctx->pc = 0x11238Cu;
            goto label_11238c;
        }
    }
    ctx->pc = 0x11235Cu;
    // 0x11235c: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x11235cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x112360: 0x6313a  dsrl        $a2, $a2, 4
    ctx->pc = 0x112360u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> 4);
    // 0x112364: 0x0  nop
    ctx->pc = 0x112364u;
    // NOP
label_112368:
    // 0x112368: 0x41878  dsll        $v1, $a0, 1
    ctx->pc = 0x112368u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << 1);
    // 0x11236c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x11236cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x112370: 0xc3102b  sltu        $v0, $a2, $v1
    ctx->pc = 0x112370u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x112374: 0x0  nop
    ctx->pc = 0x112374u;
    // NOP
    // 0x112378: 0x0  nop
    ctx->pc = 0x112378u;
    // NOP
    // 0x11237c: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11237Cu;
    {
        const bool branch_taken_0x11237c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x112380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11237Cu;
            // 0x112380: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11237c) {
            ctx->pc = 0x112368u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_112368;
        }
    }
    ctx->pc = 0x112384u;
    // 0x112384: 0xafa50008  sw          $a1, 0x8($sp)
    ctx->pc = 0x112384u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 5));
    // 0x112388: 0xffa30010  sd          $v1, 0x10($sp)
    ctx->pc = 0x112388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 3));
label_11238c:
    // 0x11238c: 0xc04463e  jal         func_1118F8
    ctx->pc = 0x11238Cu;
    SET_GPR_U32(ctx, 31, 0x112394u);
    ctx->pc = 0x112390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11238Cu;
            // 0x112390: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118F8u;
    if (runtime->hasFunction(0x1118F8u)) {
        auto targetFn = runtime->lookupFunction(0x1118F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112394u; }
        if (ctx->pc != 0x112394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118F8_0x1118f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112394u; }
        if (ctx->pc != 0x112394u) { return; }
    }
    ctx->pc = 0x112394u;
label_112394:
    // 0x112394: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x112394u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_112398:
    // 0x112398: 0x3e00008  jr          $ra
    ctx->pc = 0x112398u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11239Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112398u;
            // 0x11239c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112310u: goto label_112310;
            case 0x112340u: goto label_112340;
            case 0x112344u: goto label_112344;
            case 0x112368u: goto label_112368;
            case 0x11238Cu: goto label_11238c;
            case 0x112394u: goto label_112394;
            case 0x112398u: goto label_112398;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1123A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
