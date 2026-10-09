#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001721E8
// Address: 0x1721e8 - 0x172278
void sub_001721E8_0x1721e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001721E8_0x1721e8");
#endif

    switch (ctx->pc) {
        case 0x17221cu: goto label_17221c;
        case 0x17226cu: goto label_17226c;
        default: break;
    }

    ctx->pc = 0x1721e8u;

    // 0x1721e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1721e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1721ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1721ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1721f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1721f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1721f4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1721f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1721f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1721f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1721fc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1721fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x172200: 0x8e03004c  lw          $v1, 0x4C($s0)
    ctx->pc = 0x172200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x172204: 0x2463fffd  addiu       $v1, $v1, -0x3
    ctx->pc = 0x172204u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967293));
    // 0x172208: 0x2c630002  sltiu       $v1, $v1, 0x2
    ctx->pc = 0x172208u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x17220c: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17220Cu;
    {
        const bool branch_taken_0x17220c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x172210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17220Cu;
            // 0x172210: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17220c) {
            ctx->pc = 0x172238u;
            goto label_172238;
        }
    }
    ctx->pc = 0x172214u;
    // 0x172214: 0xc05db42  jal         func_176D08
    ctx->pc = 0x172214u;
    SET_GPR_U32(ctx, 31, 0x17221Cu);
    ctx->pc = 0x176D08u;
    if (runtime->hasFunction(0x176D08u)) {
        auto targetFn = runtime->lookupFunction(0x176D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17221Cu; }
        if (ctx->pc != 0x17221Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176D08_0x176d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17221Cu; }
        if (ctx->pc != 0x17221Cu) { return; }
    }
    ctx->pc = 0x17221Cu;
label_17221c:
    // 0x17221c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17221cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172220: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x172220u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172224: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172224u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172228: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172228u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17222c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17222cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172230: 0x805c894  j           func_172250
    ctx->pc = 0x172230u;
    ctx->pc = 0x172234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172230u;
            // 0x172234: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172250u;
    goto label_172250;
    ctx->pc = 0x172238u;
label_172238:
    // 0x172238: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172238u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17223c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17223cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172240: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172240u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172244: 0x3e00008  jr          $ra
    ctx->pc = 0x172244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172244u;
            // 0x172248: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17221Cu: goto label_17221c;
            case 0x172238u: goto label_172238;
            case 0x172250u: goto label_172250;
            case 0x17226Cu: goto label_17226c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17224Cu;
    // 0x17224c: 0x0  nop
    ctx->pc = 0x17224cu;
    // NOP
label_172250:
    // 0x172250: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172254: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x172254u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172258: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x172258u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17225c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x17225cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172260: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x172260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x172264: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x172264u;
    SET_GPR_U32(ctx, 31, 0x17226Cu);
    ctx->pc = 0x172268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172264u;
            // 0x172268: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17226Cu; }
        if (ctx->pc != 0x17226Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17226Cu; }
        if (ctx->pc != 0x17226Cu) { return; }
    }
    ctx->pc = 0x17226Cu;
label_17226c:
    // 0x17226c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17226cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172270: 0x3e00008  jr          $ra
    ctx->pc = 0x172270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172270u;
            // 0x172274: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17221Cu: goto label_17221c;
            case 0x172238u: goto label_172238;
            case 0x172250u: goto label_172250;
            case 0x17226Cu: goto label_17226c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172278u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
