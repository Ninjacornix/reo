#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001146D0
// Address: 0x1146d0 - 0x1148a0
void sub_001146D0_0x1146d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001146D0_0x1146d0");
#endif

    ctx->pc = 0x1146d0u;

    // 0x1146d0: 0x2403004b  addiu       $v1, $zero, 0x4B
    ctx->pc = 0x1146d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 75));
    // 0x1146d4: 0xc  syscall     0
    ctx->pc = 0x1146d4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1146d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1146D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1146E0u;
    // 0x1146e0: 0x2403004c  addiu       $v1, $zero, 0x4C
    ctx->pc = 0x1146e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x1146e4: 0xc  syscall     0
    ctx->pc = 0x1146e4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1146e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1146E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1146F0u;
    // 0x1146f0: 0x2403004d  addiu       $v1, $zero, 0x4D
    ctx->pc = 0x1146f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 77));
    // 0x1146f4: 0xc  syscall     0
    ctx->pc = 0x1146f4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1146f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1146F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114700u;
    // 0x114700: 0x2403004e  addiu       $v1, $zero, 0x4E
    ctx->pc = 0x114700u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x114704: 0xc  syscall     0
    ctx->pc = 0x114704u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114708: 0x3e00008  jr          $ra
    ctx->pc = 0x114708u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114710u;
    // 0x114710: 0x2403004f  addiu       $v1, $zero, 0x4F
    ctx->pc = 0x114710u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0x114714: 0xc  syscall     0
    ctx->pc = 0x114714u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114718: 0x3e00008  jr          $ra
    ctx->pc = 0x114718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114720u;
    // 0x114720: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x114720u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x114724: 0xc  syscall     0
    ctx->pc = 0x114724u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114728: 0x3e00008  jr          $ra
    ctx->pc = 0x114728u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114730u;
    // 0x114730: 0x24030051  addiu       $v1, $zero, 0x51
    ctx->pc = 0x114730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
    // 0x114734: 0xc  syscall     0
    ctx->pc = 0x114734u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114738: 0x3e00008  jr          $ra
    ctx->pc = 0x114738u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114740u;
    // 0x114740: 0x24030052  addiu       $v1, $zero, 0x52
    ctx->pc = 0x114740u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 82));
    // 0x114744: 0xc  syscall     0
    ctx->pc = 0x114744u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114748: 0x3e00008  jr          $ra
    ctx->pc = 0x114748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114750u;
    // 0x114750: 0x2403ffad  addiu       $v1, $zero, -0x53
    ctx->pc = 0x114750u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967213));
    // 0x114754: 0xc  syscall     0
    ctx->pc = 0x114754u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114758: 0x3e00008  jr          $ra
    ctx->pc = 0x114758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114760u;
    // 0x114760: 0x24030054  addiu       $v1, $zero, 0x54
    ctx->pc = 0x114760u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 84));
    // 0x114764: 0xc  syscall     0
    ctx->pc = 0x114764u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114768: 0x3e00008  jr          $ra
    ctx->pc = 0x114768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114770u;
    // 0x114770: 0x2403ffab  addiu       $v1, $zero, -0x55
    ctx->pc = 0x114770u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967211));
    // 0x114774: 0xc  syscall     0
    ctx->pc = 0x114774u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114778: 0x3e00008  jr          $ra
    ctx->pc = 0x114778u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114780u;
    // 0x114780: 0x24030056  addiu       $v1, $zero, 0x56
    ctx->pc = 0x114780u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 86));
    // 0x114784: 0xc  syscall     0
    ctx->pc = 0x114784u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114788: 0x3e00008  jr          $ra
    ctx->pc = 0x114788u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114790u;
    // 0x114790: 0x24030057  addiu       $v1, $zero, 0x57
    ctx->pc = 0x114790u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 87));
    // 0x114794: 0xc  syscall     0
    ctx->pc = 0x114794u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114798: 0x3e00008  jr          $ra
    ctx->pc = 0x114798u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1147A0u;
    // 0x1147a0: 0x2403ffa8  addiu       $v1, $zero, -0x58
    ctx->pc = 0x1147a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967208));
    // 0x1147a4: 0xc  syscall     0
    ctx->pc = 0x1147a4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1147a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1147A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1147B0u;
    // 0x1147b0: 0x24030059  addiu       $v1, $zero, 0x59
    ctx->pc = 0x1147b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 89));
    // 0x1147b4: 0xc  syscall     0
    ctx->pc = 0x1147b4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1147b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1147B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1147C0u;
    // 0x1147c0: 0x2403ffa6  addiu       $v1, $zero, -0x5A
    ctx->pc = 0x1147c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967206));
    // 0x1147c4: 0xc  syscall     0
    ctx->pc = 0x1147c4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1147c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1147C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1147D0u;
    // 0x1147d0: 0x2403005b  addiu       $v1, $zero, 0x5B
    ctx->pc = 0x1147d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 91));
    // 0x1147d4: 0xc  syscall     0
    ctx->pc = 0x1147d4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1147d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1147D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1147E0u;
    // 0x1147e0: 0x2403005c  addiu       $v1, $zero, 0x5C
    ctx->pc = 0x1147e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x1147e4: 0xc  syscall     0
    ctx->pc = 0x1147e4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1147e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1147E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1147F0u;
    // 0x1147f0: 0x2403ffa4  addiu       $v1, $zero, -0x5C
    ctx->pc = 0x1147f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967204));
    // 0x1147f4: 0xc  syscall     0
    ctx->pc = 0x1147f4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1147f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1147F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114800u;
    // 0x114800: 0x2403005d  addiu       $v1, $zero, 0x5D
    ctx->pc = 0x114800u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
    // 0x114804: 0xc  syscall     0
    ctx->pc = 0x114804u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114808: 0x3e00008  jr          $ra
    ctx->pc = 0x114808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114810u;
    // 0x114810: 0x2403ffa3  addiu       $v1, $zero, -0x5D
    ctx->pc = 0x114810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967203));
    // 0x114814: 0xc  syscall     0
    ctx->pc = 0x114814u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114818: 0x3e00008  jr          $ra
    ctx->pc = 0x114818u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114820u;
    // 0x114820: 0x2403005e  addiu       $v1, $zero, 0x5E
    ctx->pc = 0x114820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x114824: 0xc  syscall     0
    ctx->pc = 0x114824u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114828: 0x3e00008  jr          $ra
    ctx->pc = 0x114828u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114830u;
    // 0x114830: 0x2403ffa2  addiu       $v1, $zero, -0x5E
    ctx->pc = 0x114830u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967202));
    // 0x114834: 0xc  syscall     0
    ctx->pc = 0x114834u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114838: 0x3e00008  jr          $ra
    ctx->pc = 0x114838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114840u;
    // 0x114840: 0x2403005f  addiu       $v1, $zero, 0x5F
    ctx->pc = 0x114840u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x114844: 0xc  syscall     0
    ctx->pc = 0x114844u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114848: 0x3e00008  jr          $ra
    ctx->pc = 0x114848u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114850u;
    // 0x114850: 0x2403ffa1  addiu       $v1, $zero, -0x5F
    ctx->pc = 0x114850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967201));
    // 0x114854: 0xc  syscall     0
    ctx->pc = 0x114854u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114858: 0x3e00008  jr          $ra
    ctx->pc = 0x114858u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114860u;
    // 0x114860: 0x24030060  addiu       $v1, $zero, 0x60
    ctx->pc = 0x114860u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x114864: 0xc  syscall     0
    ctx->pc = 0x114864u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114868: 0x3e00008  jr          $ra
    ctx->pc = 0x114868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114870u;
    // 0x114870: 0x24030061  addiu       $v1, $zero, 0x61
    ctx->pc = 0x114870u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
    // 0x114874: 0xc  syscall     0
    ctx->pc = 0x114874u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114878: 0x3e00008  jr          $ra
    ctx->pc = 0x114878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114880u;
    // 0x114880: 0x24030062  addiu       $v1, $zero, 0x62
    ctx->pc = 0x114880u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x114884: 0xc  syscall     0
    ctx->pc = 0x114884u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114888: 0x3e00008  jr          $ra
    ctx->pc = 0x114888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114890u;
    // 0x114890: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x114890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x114894: 0xc  syscall     0
    ctx->pc = 0x114894u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114898: 0x3e00008  jr          $ra
    ctx->pc = 0x114898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1148A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
