#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182200
// Address: 0x182200 - 0x182270
void sub_00182200_0x182200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182200_0x182200");
#endif

    switch (ctx->pc) {
        case 0x182218u: goto label_182218;
        case 0x18222cu: goto label_18222c;
        case 0x182234u: goto label_182234;
        case 0x182250u: goto label_182250;
        default: break;
    }

    ctx->pc = 0x182200u;

    // 0x182200: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x182200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x182204: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x182204u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x182208: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x18220c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x18220cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x182210: 0xc042b3a  jal         func_10ACE8
    ctx->pc = 0x182210u;
    SET_GPR_U32(ctx, 31, 0x182218u);
    ctx->pc = 0x182214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182210u;
            // 0x182214: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ACE8u;
    if (runtime->hasFunction(0x10ACE8u)) {
        auto targetFn = runtime->lookupFunction(0x10ACE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182218u; }
        if (ctx->pc != 0x182218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ACE8_0x10ace8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182218u; }
        if (ctx->pc != 0x182218u) { return; }
    }
    ctx->pc = 0x182218u;
label_182218:
    // 0x182218: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x182218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18221c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x18221Cu;
    {
        const bool branch_taken_0x18221c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18221Cu;
            // 0x182220: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18221c) {
            ctx->pc = 0x182248u;
            goto label_182248;
        }
    }
    ctx->pc = 0x182224u;
    // 0x182224: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x182224u;
    SET_GPR_U32(ctx, 31, 0x18222Cu);
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18222Cu; }
        if (ctx->pc != 0x18222Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18222Cu; }
        if (ctx->pc != 0x18222Cu) { return; }
    }
    ctx->pc = 0x18222Cu;
label_18222c:
    // 0x18222c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18222Cu;
    SET_GPR_U32(ctx, 31, 0x182234u);
    ctx->pc = 0x182230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18222Cu;
            // 0x182230: 0x24440001  addiu       $a0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182234u; }
        if (ctx->pc != 0x182234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182234u; }
        if (ctx->pc != 0x182234u) { return; }
    }
    ctx->pc = 0x182234u;
label_182234:
    // 0x182234: 0x2c430020  sltiu       $v1, $v0, 0x20
    ctx->pc = 0x182234u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x182238: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x182238u;
    {
        const bool branch_taken_0x182238 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18223Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182238u;
            // 0x18223c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182238) {
            ctx->pc = 0x18225Cu;
            goto label_18225c;
        }
    }
    ctx->pc = 0x182240u;
    // 0x182240: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x182240u;
    {
        const bool branch_taken_0x182240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182240u;
            // 0x182244: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182240) {
            ctx->pc = 0x182264u;
            goto label_182264;
        }
    }
    ctx->pc = 0x182248u;
label_182248:
    // 0x182248: 0xc042c56  jal         func_10B158
    ctx->pc = 0x182248u;
    SET_GPR_U32(ctx, 31, 0x182250u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182250u; }
        if (ctx->pc != 0x182250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182250u; }
        if (ctx->pc != 0x182250u) { return; }
    }
    ctx->pc = 0x182250u;
label_182250:
    // 0x182250: 0x2c430020  sltiu       $v1, $v0, 0x20
    ctx->pc = 0x182250u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x182254: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x182254u;
    {
        const bool branch_taken_0x182254 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x182258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182254u;
            // 0x182258: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182254) {
            ctx->pc = 0x182260u;
            goto label_182260;
        }
    }
    ctx->pc = 0x18225Cu;
label_18225c:
    // 0x18225c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18225cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_182260:
    // 0x182260: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182260u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_182264:
    // 0x182264: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x182264u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182268: 0x3e00008  jr          $ra
    ctx->pc = 0x182268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18226Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182268u;
            // 0x18226c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182218u: goto label_182218;
            case 0x18222Cu: goto label_18222c;
            case 0x182234u: goto label_182234;
            case 0x182248u: goto label_182248;
            case 0x182250u: goto label_182250;
            case 0x18225Cu: goto label_18225c;
            case 0x182260u: goto label_182260;
            case 0x182264u: goto label_182264;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182270u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
